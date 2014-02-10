#include<iostream>
#include<stdio.h>
#include<map>
#include<utility>
using namespace std;
struct edge{
	int a,b;
};
int m;
int visit[103];
int fun(edge e[],int i,int n,int count){
	if(count==n)
		return 1;
	if(i == m+1)
		return 0;
	if(visit[e[i].a]==1||visit[e[i].b]==1)
		return fun(e,i+1,n,count);
	else{		
		visit[e[i].a] = 1;		
		visit[e[i].b] = 1;	
		count+=2;
		int bb= fun(e,i+1,n,count);
		visit[e[i].a] = 0;
		visit[e[i].b] = 0;
		count-=2;
		int aa=fun(e,i+1,n,count);
		return aa||bb;
	}	
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		map< pair<int,int>, bool> Map;
		int n;
		cin>>n>>m;
		int c_m;
		edge e[m+2]; 
		for(int i=1;i<=m;i++)
			cin>>e[i].a>>e[i].b;
		if(n%2)
		{
			cout<<"NO\n";
			continue;
		}
		if(m<n/2){
			cout<<"NO\n";
			continue;
		}
		c_m=m;
		for(int i=1;i<=m;i++)
		{
			if(Map[make_pair(e[i].a,e[i].b)]){
				c_m--;
			}
			else
				Map[make_pair(e[i].a,e[i].b)]=true;
		}
		if(c_m<n/2){
			cout<<"NO\n";
			continue;
		}
		if(fun(e,1,n,0))
			cout<<"YES\n";
		else
			cout<<"NO\n";		
	}	
	}
	

