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
	int t,i;
	cin>>t;
	while(t--)
{
	int rest=0;
	map<int,int> check;
	map<int,int> check2;
	nnode node[1002];
	int n,x,y;
	int bob=0;
	cin>>n;
		for( i=1;i<=n;i++)
{
	cin>>node[i].x>>node[i].y;
}
	for( i=1;i<=n;i++)
{
	check[node[i].x]++;
	check2[node[i].y]++;
	
}
	while(1)
{
	int max=0,i,max2=0,val,val2;
//for(int i=1;i<=n;i++)
//cout<<check[node[i].x]<<" ";
//cout<<"and" <<endl;
//for(int i=1;i<=n;i++)
//cout<<check2[node[i].y]<<" ";
//cout<<endl;

	for( i=1;i<=n;i++)
{
	if(check[node[i].x]>max)
{	
	val=node[i].x;	
	max=check[node[i].x];	
}
}
	for( i=1;i<=n;i++)
{
	if(check2[node[i].y]>max2)
{
		val2=node[i].y;
		max2=check2[node[i].y];	
}
}
	if(max==1&&max2==1)
{
	bob=bob+n-rest;
	break;		
}



	if(max>max2)
{
	rest=rest+max;
	check[val]=0;
	bob++;
	for(i=1;i<=n;i++)
	if(node[i].x==val)
{
	check2[node[i].y]--;
}
		
}
else
{
	rest=rest+max2;
	check2[val2]=0;
	bob++;
	for(i=1;i<=n;i++)
	if(node[i].y==val2)
{
	check[node[i].x]--;
}

}
if(bob==90)
break;
	if(rest==n)
	break;
}
cout<<bob<<endl;
}	
}
