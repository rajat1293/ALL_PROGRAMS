#include<stdio.h>
#define MOD 1000000007
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
int n,k;
scanf("%d%d",&k,&n);

long long m=1;
long long nm=0;

while(k--)
{
long long tm=m;
m=nm;
nm=((nm*(n-1))%MOD+(tm*(n))%MOD)%MOD;
}
printf("%lld\n",m);
}
return 0;
}
