#include<stdio.h>
#include<math.h>
#define MOD 1000000007  

unsigned long long  kiss(unsigned long long int  N)
{
	if(N==1)
	return (2);
	else 
	{
		return( (kiss(N-1)%MOD + (unsigned long long )pow(2,N/2)%MOD)%MOD);
	}		
}
int main()
{
	int t;
unsigned long long s;
	unsigned long long N;
	scanf("%d",&t);
	while(t--)
	{
	scanf("%llu",&N);
	s=kiss(N);
	printf("%llu\n",s);
	}		
}
