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
	  long long s;
	  long long n;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%lld",&n);
	if(n%2==0)
s=(((4*((((long long )p(2,(n-2)/2))%MOD)-1))%MOD+(((long long )p(2,n/2)%MOD)+2)%MOD)%MOD);
	else 
s=(4*(((long long  )p(2,(n-1)/2)%MOD)-1)%MOD+2)%MOD;
	printf("%lld\n",s);
	}
			return 0;
}
