#include <cstring>
#include<cstdio>
#include <algorithm>
using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN];
struct entry {
int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;
int cmp(struct entry a, struct entry b)
{
return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
//----------
int lcp(int x, int y)
{
int k, ret = 0;
if (x == y) return N - x;
for (k = stp - 1; k >= 0 && x < N && y < N; k --)
if (P[k][x] == P[k][y])
x += 1 << k, y += 1 << k, ret += 1 << k;
return ret;
}
//----------------
int main()
{
gets(A);
for (N = strlen(A), i = 0; i < N; i ++)
P[0][i] = A[i] - 'a';
for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
{
for (i = 0; i < N; i ++)
{
L[i].nr[0] = P[stp - 1][i];
L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
L[i].p = i;
}
sort(L, L + N, cmp);
for (i = 0; i < N; i ++)
P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
}
//int r=0;
//printf("%d\n",stp);
//for(i=0;i<N;i++)
//printf("%d ",P[stp-1][i]);
//for(i=0;i<N-1;i++)
//{
//r+=lcp(i,i+1);	
//}
return 0;
}
