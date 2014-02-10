//AUTHOR ---RAJAT GAMBHIR------
//DATE 
#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<utility>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	int cost=0,countt=0;
	int n,m,c2,c3;
	char a[104][104];
	cin>>n>>m>>c2>>c3;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	cin>>a[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
{
	if(a[i][j]=='W')
{
	countt++;
}
}
	cout<<countt<<endl;		
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
{
	if(a[i][j]=='W')
{
	cout<<"2"<<" "<<i<<" "<<j<<endl;	
}
}
}
}

