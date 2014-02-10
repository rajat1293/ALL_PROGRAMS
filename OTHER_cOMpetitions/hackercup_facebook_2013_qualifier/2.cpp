#include<iostream>
#include<queue>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct player
{
	char a[100];
	int shot;
	int height;
 bool operator ()( const player& a, const player& b)
 {
 	if(a.shot==b.shot)
 	return a.height>b.height;
 	return a.shot>b.shot;
 }
}; 
int main()
{
	int t;
	 char con[100][100];
	cin>>t;
	//freopen("ou.txt","w",stdout);
	for(int i=1;i<=t;i++)
	{
		int n,m,p,shot,height;
	    cin>>n>>m>>p;
		player pp[n+2];
		for(int j=1;j<=n;j++)
		{
		    cin>>pp[j].a>>pp[j].shot>>pp[j].height;
		}
		cout<<endl;
		sort(pp+1,pp+n+1,player());
		for(int j=1;j<=n;j++)
		{
		    cout<<pp[j].a<<" "<<pp[j].shot<<" "<<pp[j].height;
			cout<<endl;
		}
	}
}
