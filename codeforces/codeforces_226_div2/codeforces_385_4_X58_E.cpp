#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);

struct point {
    double x, y;
    point(double a = 0, double b = 0): x(a), y(b) {}
};

double dis(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double dot(point a, point b, point c) {
	return (b.x-a.x)*(c.x-a.x) + (b.y-a.y)*(c.y-a.y);
}

struct light {
    point o;
    double a;
}lg[25];

double dp[1<<20];
int n, l, r;
point R;

double dfs(int ms) {
    if (dp[ms] >= 0) {
        return dp[ms];
    }
    double maxs = 0;
    for (int i = 0; i < n; i++) if (ms&1<<i) {
        double d = dfs(ms^1<<i);
        if (d >= r - l) {
            maxs = r - l;
            break;
        }
        point o = point(l+d, 0);
        double len = dis(o, lg[i].o);

        double b = acos(dot(o, lg[i].o, R)/(len*dis(o, R)));
        double c = PI - lg[i].a - b;
        if (c <= 0) {
            maxs = r - l;
            break;
        }

        double dt = len*sin(lg[i].a)/sin(c);
        double tp = d + dt;
        if (tp > maxs) maxs = tp;
    }
    return dp[ms] = maxs;
}

int main() {
    int m, i, j;
    while (~scanf("%d%d%d", &n, &l, &r)) {
        for (i = 0; i < n; i++) {
            int x, y, a;
            scanf("%d%d%d", &x, &y, &a);
            lg[i].o = point(x, y);
            lg[i].a = a*PI/180;
        }
        m = 1 << n;
        for (i = 0; i < m; i++) dp[i] = -1;
        R = point(r, 0);
        printf("%.8f\n", min(dfs(m-1), r-l+0.0));;
    }
    return 0;
}
/*
2 3 5
3 1 45
5 1 45

1 0 1
1 1 30

1 0 1
1 1 45

1 0 2
0 2 90
*/
