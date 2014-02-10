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
		queue<int> Q1,Q2,Q11,Q22;
		int n,m,p,shot,height;
	    int lteam1,lteam2;
		cin>>n>>m>>p;
		player pp[n+2];
		for(int j=1;j<=n;j++)
		{
		    cin>>pp[j].a>>pp[j].shot>>pp[j].height;
		}
		sort(pp+1,pp+n+1,player());
		if(n%2==0)
		{
			lteam1=n-1;
			lteam2=n;
		}
		else
		{
			lteam1=n;
			lteam2=n-1;
		}
		for(int j=2*p-1;j>=1;j-=2)
			{
				Q1.push(j);
			}
			for(int j=2*p+1;j<=lteam1;j+=2)
			Q2.push(j);
			int sss=m;
		while(m--)
		{
			int ra=Q2.front();
			Q2.pop();
			int sa=Q1.front();
			Q1.pop();
			Q1.push(ra);
			Q2.push(sa);		
		}
	for(int j=1;j<=p;j++)
	{
		int ra=Q1.front();
		Q1.pop();
		cout<<pp[ra].a<<" ";	
	}
	//--------------------
		for(int j=2*p;j>=2;j-=2)
			{
				Q11.push(j);
			}
			for(int j=2*p+2;j<=lteam2;j+=2)
			Q22.push(j);
			while(sss--)
		{
			int ra=Q22.front();
			Q22.pop();
			int sa=Q11.front();
			Q11.pop();
			Q11.push(ra);
			Q22.push(sa);		
		}
		for(int j=1;j<=p;j++)
	{
		int ra=Q11.front();
		Q11.pop();
		cout<<pp[ra].a<<" ";	
	}
		
	
	
	
	}
}
//a bit manipulations done ie the code should be of some prescribed form okk
// the case of 2*p==n should be handled easily this is it

