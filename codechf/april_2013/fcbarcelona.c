//AUTHOR ---@RAJAT GAMBHIR------
//COPYRIGHTS.....
//#include<iostream>
#include<stdio.h>
#include<math.h>
#define MOD 1000000007  
long long p(int n,int m)
{
if(m==0) return 1;

long long x=p(n,m/2);
if(m%2==0)
return (x*x)%MOD;
else
return (((x*x)%MOD)*n)%MOD;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		long long s=0;
		scanf("%d%d",&n,&k);
		if(n%2==0)
		s=p(k,n/2);
		if(n<3)
		;//s=(s+k*p(k-1,0))%MOD;
		else
		s=(s+k*p(k-1,n-3))%MOD;
	printf("%d\n",s);
	}
	return 0;
}


