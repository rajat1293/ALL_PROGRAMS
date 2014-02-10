//AUTHOR ---RAJAT GAMBHIR------
//DATE 11/8/13 ,time 1700hrs
#include<iostream>
#include<stdio.h>
#include<math.h>
#define MODD  1000000007
using namespace std;
long long count,ans;
int MOD;
long long poww(long long n,long long m) 
{ 
  	if(m==0) return (1)%MOD;
   	long long x=poww (n,m/2);
    if(m%2==0) return (x*x)%MOD; 
	else return (((x*x)%MOD)*n) %MOD;
}
long long power[42];
int main()
{
	long long t,upper,d,m;
	scanf("%lld",&t);
	while(t--)
	{
		count=0;
		ans = 0;
		scanf("%lld%lld%lld%lld",&upper,&d,&m,&MOD);
		for(int i=0;i<MOD;i++)
			{
			power[i]=poww(i,d);
		//	cout<<power[i];
		   }
		for(int i=0;i<=MOD-1&&i<=upper;i++)
		{
			for(int j=0;j<=MOD-1&&j<=upper;j++)
			{
				for(int k=0;k<=upper&&k<=MOD-1;k++)
				{
					if((power[i]+power[j]+power[k])%MOD==m) {
						
						count=((upper-i)/MOD+1)%MODD;
						count *= ((upper-j)/MOD+1)%MODD;
						count %= MODD;
						count *= ((upper-k)/MOD+1)%MODD;
						count %= MODD;
						ans += count;
						ans %= MODD;
					}
				}
			}
		}
		printf("%lld\n",ans);	
    }
    return 0;

}
    

