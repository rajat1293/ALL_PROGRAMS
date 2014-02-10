#include<bits/stdc++.h>
using namespace std;
#define gc getchar_//unlocked
struct node{
	int inC;
	int prof[1002];
	int input[1002];
	int output[1002];
bool operator () (const node & a,const node &b){
	return a.prof > b.prof;
}
};
	node no[1002];	
//-----------------------
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
//------------------------
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k,take;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++){
			cin>>no[i].inC;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			cin>>no[i].input[j];
			//cin>>no[i].prof;
		}
		for(int i=1;i<=;ni++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>no[i].output[j];
				no[i].prof[j] = no[i].input[j] - no[i].output[j];
			}
		}
		sort(no+1,no+1+n,node());
		int ans=0;
		for(int i=1;i<=k;i++)
			ans += no[i].prof;
		for(int i=k+1;i<=n;i++)
			ans += no[i].input;
		
		
		
		
		
