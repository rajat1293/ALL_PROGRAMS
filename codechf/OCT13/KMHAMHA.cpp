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
#include<map>
struct nnode{
	int x;
	int y;
	};	
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	int val,rval,rest=0;
	map<int,bool> checkk;
//	map<int,bool> check;
//	map<int,bool> check2;
	map<int,bool> checkk2;
	nnode node[1002];
	int n,x,y;
	int bob=0;
	cin>>n;
		for(int i=1;i<=n;i++)
{
	cin>>node[i].x>>node[i].y;
}
	while(1)
{
	int countt=1;
	int max=0;
	//	int sss;
	for(int i=1;i<=n;i++)
{
	//if(check[i]==sss)
	//continue;
	if(checkk[node[i].x]==1)
	continue;
	if(checkk2[node[i].y]==1)
	continue;
	//check[i]=1;
	countt=1;
	for(int j=i+1;j<=n;j++)
{
	if(checkk[node[j].x]==0&&checkk2[node[j].y]==0&&node[i].x==node[j].x)
{
		countt++;	
}
}
	if(countt>max)
{
	max=countt;	
	val=node[i].x;
}
}
	int countt2,max2=0;
	int val2;
	for(int i=1;i<n;i++)
{
	//if(check[i]==1)
	//continue;
	//check[i]=1;
	if(checkk[node[i].x]==1)
	continue;
	if(checkk2[node[i].y]==1)
	continue;
	countt2=1;
	for(int j=i+1;j<=n;j++)
{
	if(checkk[node[j].x]==0&&checkk2[node[j].y]==0&&node[i].y==node[j].y)
{
		countt2++;	
}
}
	if(countt2>max2)
{
	max2=countt2;	
	val2=node[i].y;
}
}
	if(max==1&&max2==1)
{
	bob=bob+n-rest;
	break;
}
	if(max>max2)
{
	rval=val;
	checkk[rval]=1;
	bob++;
	rest+=max;
}
else
{
	rval=val2;
	checkk2[rval]=1;
	bob++;
	rest+=max2;
}
if(rest==n)
	break;			
	
}
cout<<bob<<endl;
}	
}
