#include<stdio.h>
typedef long long ll ;
int main()
{
	ll k,sum=0,n;
	scanf("%lld",&n);
	while(k!=0)
{
	k=n/5;
	sum=sum+k;
	n=n/5;
}
printf("%lld",sum);	
return 0;
}

