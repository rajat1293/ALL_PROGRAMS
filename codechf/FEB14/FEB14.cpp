#include<bits/stdc++.h>
using namespace std;
#define gc getchar//_unlocked
void scanint(int &x)
{
	register int c=gc();
	x=0;
	int neg=0;
	for(;((c<48||c>57)&&c!='-');c=gc());
	if(c=='-')
	{
		neg=1;c=gc();
	}
	for(;c>47&&c<58;c=gc())
	{
		x=(x<<1)+(x<<3)+c-48;
	}
		if(neg)
		x=-x;
	}
int main(){
	//int t;
	unordered_map<int,int> M;
	int a;
	//while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		 {
		 	cin>>a;
		 	if(M[a]==0){
		 		M[a] = min(i,n-i+1);
		 	}
		 	else
		 	{
		 		int mm = min(i,n-i+1);
		 		if(M[a]>mm)
		 			M[a]  = mm;
		 	}
		 }
		 int ans=INT_MAX;
		for(auto i = M.begin();i != M.end();i++)
			{
					
				if( M[i->first] && M[k - i->first] && i->first != (k- i->first))
				{
					int x = max(M[i->first],M[k - i->first]);
						if(ans>x)
							ans = x;
				}
			}
			if(ans != INT_MAX)
			cout<<ans<<endl;
			else
			cout<<"-1\n";		
}
