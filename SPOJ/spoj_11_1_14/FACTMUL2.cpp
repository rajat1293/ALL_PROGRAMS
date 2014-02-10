#include <iostream>
#include<stdio.h>
#include <set>
using namespace std;
#define MOD  109546051211LL
#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked
typedef  long long ll;
//-----------------------------
ll mulmod(ll a,ll b,ll c){
	ll x=0,y=a%c;
	while(b>0){
		if(b%2==1){
			x=(x+y)%c;
		}
		y=(y*2)%c;
		b /=2;
	}
	return x%c;
}
int main()
{
	ll n;
	ll t=1LL,u=1LL;
	scanf("%lld",&n);
//	if(n >= 587117)
//	{
//		printf("0\n");
//		return 0;
//	}
	for(ll i=1LL;i<=n;i++){
		t=(t*i)%MOD;//new factorial
		u=(t*u)%MOD;		// product
	}
	printf("%d\n",u);
}
