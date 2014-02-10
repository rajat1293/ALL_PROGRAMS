#include<stdio.h>
#define MOD 1000000007
typedef unsigned long long int ull;
ull j;
ull poww(ull n,ull m) 
{ 
  	if(m==0) return (1)%MOD;
   	ull x=poww (n,m/2);
    if(m%2==0) return (x*x)%MOD; 
	else return (((x*x)%MOD)*n) %MOD;
}
void bin(ull n)
{
	if(n==1)
	j=j*10+n;
	else
{
		bin(n/2);
		j=j*10+n%2;
}
}
int main()
{
   ull t;
	scanf("%llu",&t);
	while(t--)
{
	j=0;
	 ull n;
	scanf("%llu",&n);
	bin(n);		
	ull u=poww(2,j);
	printf("%llu\n",u*u%MOD);
}
return 0;
}
	
