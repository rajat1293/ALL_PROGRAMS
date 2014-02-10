#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long llabs(long long x)
{
	return x>=0?x:-x;
}
int main()
{
	long long n,i,cost=0,b,j,X,k=0;
	scanf("%lld",&n);
	long long  A[100004];
	A[0]=0;
	for(i=1;i<=n;i++)
	scanf("%lld",&A[i]);
	scanf("%lld",&X);
	sort(A+1,A+n+1);
	while(1)
{	
		for(i=1;i<=n;i++)
{
		if((A[i]+k)>=0)
		break;
}
if(i-1>X)
{
k=k+(llabs(A[i-1]));
cost=cost+X*llabs(A[i-1]);
}
else
{
	for(i=1;i<=n;i++)
	if((A[i]+k)<0)
	cost+=llabs(A[i]+k);
	else
	break;
	break;	
}
}
printf("%lld",cost);
}

