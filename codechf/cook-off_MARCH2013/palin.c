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
	long long s,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",p(26,n/2));
		if(n%2==0){
		s=((252*((MOD+p(26,n/2)-1)%MOD))%MOD);
s=(s*p(25,MOD-2))%MOD;
		}		
		else
		s=(13*((2*(2*((p(26,n/2)-1)%MOD))%MOD)%MOD)%MOD/25+p(26,(n+1)/2)%MOD)%MOD;
		printf("%lld\n",s);	
	}
	return 0;	
}
