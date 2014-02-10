#include<stdio.h>
long long fact(long long n,long long  k)
{
	int i;
	long long  c=1;
	for(i=1;i<=k;i++)
		{c=c*(n-i+1);
		c=c/(i);}
		for(i=1;i<=k;i++)
		c=c/i;
	return c;
	}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n,k;
	scanf("%lld",&n);	
	k=fact(2*n,n);
	k=k/3;
	printf("%lld\n",k);		
	}
	return 0;
	
}
