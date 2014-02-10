#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;
int main()
{
	int store[303][303];
	int n,a,count=0,k;
	cin>>n;
	vector<vector<int> > V(n+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		cin>>a;	
	    V[i].push_back(a);
	}
	for(int i=1;i<=n;i++)
	{
		map< pair<int,int> , bool > M;
		for(int j=1;j<=n;j++)
		{
			for(k=1;k<i;k++)
			if(	M[make_pair(i,j)]==M[make_pair(k,j)])
			{
				M[make_pair(i,j)]=true;
				break;
			}
			if(k==i)
				store[i][j]=store[i][j-1]+1;
			else
				store[i][j]=store[i][j-1];
		}
	}
	cin>>Q;
	while(Q--)
	{
		cin>>x1>>y1>>x2>>y2;
		cout<<store[x2][y2]
	}
	
	
	
}
