//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
#include<math.h>
long long gcd(long long a,long long b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}
	
int main()
{
	int t;
	long long i;
	scanf("%d",&t);
	while(t--)
{
	long long  n,sum=0;
	scanf("%lld",&n);
	long long root=sqrt(n);
	for( i=1;i<=root;i++)
	sum+=n/i;
	sum*=2;
	sum=sum-root*root;
	long long div=gcd(n*n,sum);
	printf("%lld/%lld\n",sum/div,n*n/div);
}
}
	


