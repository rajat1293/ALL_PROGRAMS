// WHAT'S WRONG WITH YOU GUYS??? WTF IS PENTIUM 3??? PLEASE UPGRADE SERVERS! IT'S RIDICULOUS TO TEST SOLUTIONS ON 9-YEAR OLD SYSTEM!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())   
#ifdef _WIN32
#define LLD "%I64d"
#elif linux
#define LLD "%lld"
#else
#error Invalid OS
#endif

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

const int MOD = 1000000007;
void madd(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}

const int MAXC = 260000;

int sgn(int x) { return x < 0 ? -1 : !!x; }

int gx, gy;
set<pii> locked;
set<pii> reach2;

int xs[2], ys[2];

void dfs2(int x, int y) {
  if (x < -MAXC || x > MAXC) return;
  if (y < -MAXC || y > MAXC) return;
  if (locked.count(mp(x, y))) return;
  if (reach2.count(mp(x, y))) return;

  reach2.insert(mp(x, y));
  for (int i = 0; i < 2; i++)
    dfs2(x - xs[i], y - ys[i]);
}

map<pii, int> ids;
vector<pii> es;

int dfs1(int x, int y) {
  if (x < -MAXC || x > MAXC) return -1;
  if (y < -MAXC || y > MAXC) return -1;
  if (locked.count(mp(x, y))) return -1;
  if (!reach2.count(mp(x, y))) return -1;
  if (ids.count(mp(x, y))) return ids[mp(x, y)];

  int cid = sz(ids);
  ids[mp(x, y)] = cid;
  es.pb(mp(-1, -1));
  for (int i = 0; i < 2; i++) {
    int a = dfs1(x + xs[i], y + ys[i]);
    if (a >= 0) {
      if (es[cid].first < 0) es[cid].first = a;
      else es[cid].second = a;
    }
  }
  return cid;
}

vi was;
vi anses;
int fini;

int dfs(int x) {
  if (was[x] == 1) throw x;
  if (was[x]) return anses[x];

  was[x] = 1;
  anses[x] = 0;
  if (x == fini) madd(anses[x], 1);
  if (es[x].first >= 0) madd(anses[x], dfs(es[x].first));
  if (es[x].second >= 0) madd(anses[x], dfs(es[x].second));
  was[x] = 2;
  return anses[x];
}

bool getKs(int x, int y, int &k1, int &k2) {
  for (k1 = 0; k1 <= 251000; k1++) {
    int nx2 = x - xs[0] * k1;
    int ny2 = y - ys[0] * k1;

    if (nx2 && !xs[1]) continue;
    if (ny2 && !ys[1]) continue;
    if (xs[1] && nx2 % xs[1]) continue;
    if (ys[1] && ny2 % ys[1]) continue;
    if (xs[1] && ys[1] && (nx2 / xs[1] != ny2 / ys[1])) continue;

    k2 = -1;
    if (xs[1]) k2 = nx2 / xs[1];
    else k2 = ny2 / ys[1];
    if (k2 < 0) continue;
    return true;
  }
  return false;
}

const int MAXCV = 300000;
int facs[MAXCV + 1];
int ifacs[MAXCV + 1];

int getC(int n, int k) {
  assert(0 <= k && k <= n && n <= MAXCV);
  return mmul(facs[n], mmul(ifacs[k], ifacs[n - k]));
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  facs[0] = 1;
  for (int i = 1; i <= MAXCV; i++)
    facs[i] = mmul(facs[i - 1], i);
  for (int i = 0; i <= MAXCV; i++)
    ifacs[i] = mpow(facs[i], MOD - 2);

  int TC;
  scanf("%d", &TC);
  for (int TN = 0; TN < TC; TN++) {
    int k;
    scanf("%d%d%d", &gx, &gy, &k);
    scanf("%d%d", &xs[0], &ys[0]);
    scanf("%d%d", &xs[1], &ys[1]);

    if (xs[0] * ys[1] - ys[0] * xs[1] != 0) {
      int gk1, gk2;
      vector<pii> _lks(k);
      for (int i = 0; i < k; i++)
        scanf("%d%d", &_lks[i].first, &_lks[i].second);

      if (!getKs(gx, gy, gk1, gk2)) printf("0\n");
      else {
        vector<pii> lks;
        for (int i = 0; i < k; i++) {
          int k1, k2;
          if (getKs(_lks[i].first, _lks[i].second, k1, k2)) {
            if (k1 <= gk1 && k2 <= gk2) {
              lks.pb(mp(k1, k2));
            }
          }
        }
        sort(lks.begin(), lks.end());

        k = sz(lks);
        vi subans(1 << k);
        for (int m = sz(subans) - 1; m >= 0; m--) {
          bool g = true;
          pii prev(0, 0);
          int cans = 1;
          for (int i = 0; i < k; i++) if (m & (1 << i)) {
            int dx = lks[i].first - prev.first;
            int dy = lks[i].second - prev.second;

            if (dx < 0 || dy < 0) { g = false; break; }
            cans = mmul(cans, getC(dx + dy, dx));
            prev = lks[i];
          }
          if (!g) continue;
          {
            int dx = gk1 - prev.first;
            int dy = gk2 - prev.second;
            cans = mmul(cans, getC(dx + dy, dx));
          }

          subans[m] = cans;
          for (int supm = m; supm < sz(subans); supm = (supm + 1) | m)
            if (supm > m) {
              madd(subans[m], MOD - subans[supm]);
            }
        }
        printf("%d\n", subans[0]);
      }
    } else {
      locked.clear();
      for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        locked.insert(mp(x, y));
      }
      reach2.clear();
      dfs2(gx, gy);

      es.clear();
      ids.clear();
      dfs1(0, 0);

      int ans;
      try {
        if (ids.count(mp(0, 0)) && ids.count(mp(gx,gy))) {
          was = vi(sz(ids), 0);
          anses = vi(sz(ids), -1);
          fini = ids[mp(gx, gy)];
          ans = dfs(ids[mp(0, 0)]);

          if (ans > 0 && xs[0] == xs[1] && ys[0] == ys[1])
            ans = 1;
        } else {
          ans = 0;
        }
      } catch (...) {
        ans = -1;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}

