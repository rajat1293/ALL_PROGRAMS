#include<stdio.h>
int fact( unsigned long long n)
{
unsigned long long i=1,c=1;
	int k;
	while(i<=n)
	{
	c=c*i;
	i++;
	}
	k=c%1000000007;
	return k;
}
int main()
{
	int t;
	char m;
	unsigned long long N;
	scanf("%d",&t);	
	scanf("%c",&m);	
while(t--)
{
	fflush(stdin);
	scanf("%llu",&N);
printf("%d",(fact(N)));
}}
