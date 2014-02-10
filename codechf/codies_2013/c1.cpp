#include<stdio.h>
#include<iostream>
using namespace std;
long long ncr[100][100];
long long a[100][100];
void solve()
{
a[1][1]=1;
int n,m,p,q;
cin >> n >> m;
cin >> p >> q;
/*long long ans=ncr[n+m-2][n-1]-ncr[p+q-2][p-1]*ncr[n+m-p-q][n-p];
printf("%lld\n",ans);*/
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
{
if(i==1&&j==1) continue;
if(i==p&&j==q)
{
a[i][j]=0;
continue;
}
a[i][j]=a[i-1][j]+a[i][j-1];
}
}
printf("%lld\n",a[n][m]);
}
main()
{
//cout << 26362427080-592623304;
/*ncr[0][0]=1;
ncr[1][0]=1;ncr[1][1]=1;
for(int i=2;i<=50;i++)
{
ncr[i][0]=1;
for(int j=1;j<=i;j++)
{
ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
}
}*/
//cout << ncr[0][0];
int t;
cin >> t;
for(int i=0;i<t;i++) solve();
}
