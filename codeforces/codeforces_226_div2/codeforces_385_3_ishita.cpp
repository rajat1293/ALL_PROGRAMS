/* @author Ishita Gupta*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vvi vector< vi >
#define vs vector<string>
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fori(s,e) for(int i=s;i<=e;i++)
#define forj(s,e) for(int j=s;j<=e;j++)
#define fork(s,e) for(int k=s;k<=e;k++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define aa first
#define bb second
#define N 10000003
using namespace std;
vector<vi> factors;
int f[N], spd[N];
void primeFactors()
{
    int x = sqrt (N), j;
    fori (2, x)
    if (spd[i] == 0)
        for (j = i; j <= N; j += i)
            spd[j] = i;
    fori(2,N) if(spd[i]==0) spd[i]=i;
}

int main()
{
    std::ios_base::sync_with_stdio (false);
    int i, j, k, t, n, m, x, y, l, r, maxe = 0;
    primeFactors();
    // cout << "done \n";
    cin >> n;
    fori (1, n)
    {
        cin >> x;
        while (x>1)
        {
            int y = spd[x];
            while (x % y == 0)
            {
                x = x / y;
            }
            f[y]++;
        }
    }
    cerr<< "done";
    fori (1, N - 1)
    {
        //cout << i << " " << f[i] << endl;
        f[i] += f[i - 1];
    }
    cin >> m;
    while (m--)
    {
        ll ans = 0;
        cin >> l >> r;
        if (l >= N)
            ans = 0;
        else if (r >= N)
            ans = f[N - 1] - f[l - 1];
        else
            ans = f[r] - f[l - 1];
        cout << ans << endl;
    }
    return 0;
}
