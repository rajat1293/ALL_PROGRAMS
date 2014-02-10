#include<cstdio> 
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;  
#define MAX  100009 
#define MAXR 100
#define MOD 1000000009
typedef long long ll;

ll p(int q,ll n)
{
	 ll ans;
	 if(n==1)
       		return q;
	else {
		ans=p(q,n/2)%MOD;
		ans*=ans;
		ans%=MOD;
		if(n%2)
		{
				  ans*=q;
				  ans%=MOD;
		}
	}
	return ans;
}
struct ht {     
	ll nr[2], p; 
} h[MAX]; 

ll pos[MAXR][MAX];

int cmp(struct ht a, struct ht b) {     
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0); 
}  

ll lcp(ll x, ll y,ll n,ll a) {    
	 ll k;
	 ll ret = 0;   
	 if (x == y) return n - x;     
	 for (k = a - 1; k >= 0 && x < n && y < n; k --)         
	 	if (pos[k][x] == pos[k][y])             
		 x += 1 << k, y += 1 << k, ret += 1 << k;
	return ret; 
}
 
int main() {     
	int t;
	ll a,b;
	scanf("%d",&t);		
		while(t--) {
		int count=0;
		ll n;
		scanf("%lld",&n);		
		ll ht[n],hd[n];
		ll tot = (((n*(n-1))%MOD)*p(2,MOD-2))%MOD;
		for(int i=0;i<n;i++) 
		scanf("%lld",&ht[i]);		
			for(int i=1;i<n;i++) 
				hd[i-1] = ht[i] - ht[i-1];		
		     n--;
		for (int i = 0; i < n; i ++) {        
			pos[0][i] = hd[i]; 
			
		}  	
		for ( a= 1, b = 1; b >> 1 < n; a ++, b <<= 1)     {         
			for (int i = 0; i < n; i ++){             
				h[i].nr[0] = pos[a - 1][i];             
				h[i].nr[1] = i + b < n ? pos[a - 1][i + b] : -200;             
				h[i].p = i;         
			}         
			sort(h, h + n, cmp);         
			for (int i = 0; i < n; i ++) {             
				pos[a][h[i].p] = i > 0 && h[i].nr[0] == h[i - 1].nr[0] && h[i].nr[1] == h[i - 1].nr[1] ? pos[a][h[i - 1].p] : i;
			}
		} 
		ll  sum = 0;
		for(int j=0;j<n-1;j++) {
		sum = (sum + (lcp(h[j].p,h[j+1].p,n,a-1))%MOD )%MOD ;
			}
	printf("%lld\n",(tot - sum)%MOD );
	}
	
}   
