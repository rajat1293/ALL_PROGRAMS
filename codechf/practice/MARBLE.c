#include<stdio.h>
int mini( int a,int b)
{
if(a<=b)
return a;
else
return b;
}
long long fact(int n,int k)
{
	int i;
	long long  c=1;
	for(i=1;i<=k;i++)
		{c=c*(n-i+1);
		c=c/i;}
	return c;
	}
int main()
{
	int f,t,n,k;
	long long s;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%d",&k);
	scanf("%d",&n);
	f=mini(n-1,k-n);
		s=fact(k-1,f);
		printf("%lld\n",s);	
	}
	return 0;		
}
