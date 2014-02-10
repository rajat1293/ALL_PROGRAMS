#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 20;
const double pi = atan(1.0) / 45; // pi = Pi/2;
struct In{
    double x, y, a;
}a[N<<1];
int n, L, R;
double dp[1<<N][N+1];
bool vis[1<<N][N+1];

double calc(double x, In e){
    double X = e.x, Y = e.y, A = e.a, ans;
    if (X >= x){
        double ang = atan((X-x)/Y);
        double det = Y * tan(fabs(ang-A*pi));
        if (A*pi <= ang){
            ans = X - det;
        }else {
            ans = X + det;
        }
    }else {
        double ang = atan((x-X)/Y);
        if (ang/pi + A >= 90.0)return R;
        double det = Y * tan(ang+pi*A);
        ans = det + X;
    }
    return ans;
}

double dfs(int s, int cnt){
    if (!cnt)return L;
    if (vis[s][cnt])return dp[s][cnt];
    double Max = L;
    for (int i = 0; i < n; i++){
        if ((1<<i) & s){
            Max = max(Max, calc(dfs(s-(1<<i), cnt-1), a[i]));
        }
    }
    vis[s][cnt] = true;
    return dp[s][cnt] = Max;
}
double get(double x){return x >= R ? R - L: x - L;}

int main(){
    memset(vis, false, sizeof(vis));
    scanf("%d%d%d", &n, &L, &R);
    for (int i = 0; i < n; i++)scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].a);
    printf("%.10f\n", get(dfs((1<<n)-1, n)));
    return 0;
}
