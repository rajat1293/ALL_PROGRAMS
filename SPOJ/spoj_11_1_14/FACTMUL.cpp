#include <iostream>
#include<stdio.h>
#include <set>
using namespace std;
#define MOD  109546051211LL
#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked
typedef  long long ll;
inline  ll readInt()
{
int flag=1;
ll N = 0;
char c;
while (1)
{
c=GETCHAR();
if(c>='0'&&c<='9') {N = N * 10 + c - '0';flag=0;}
else if(flag!=1) break;
}
return N;
}
//-------------------------------
void out(ll N){
if(!N) PUTCHAR('0');
char pb[10];
int pi = 0;
while(N) pb[pi++] = (N%10) + '0', N /= 10;
while(pi) PUTCHAR(pb[--pi]);
}
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
	ll t=1,u=1;
	scanf("%lld",&n);
//	if(n >= 587117)
//	{
//		printf("0\n");
//		return 0;
//	}
	for(ll i=1;i<=n;i++){
		t=(t*i)%MOD;//new factorial
		u=(t*u)%MOD;		// product
	}
	printf("%d\n",u);
}
