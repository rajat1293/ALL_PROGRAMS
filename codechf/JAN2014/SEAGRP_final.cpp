#include<iostream>
#include<string.h>
#include<stdio.h>
#include<map>
#include<utility>
#define NIL -1
using namespace std;
struct edge{
	int a,b;
};
int m;
int n;
int nn;
int check[102][102];
edge e[102];
int visit[103];
int fun(int i,int count){
	if(count==nn)
		return 1;
	//	cout<<i;
	//	cout<<e[i].a<<" "<<e[i].b;
	if(i == m+1)
		return 0;
	if(visit[e[i].a]==1||visit[e[i].b]==1){
		if(check[i+1][count]==NIL)
		 check[i+1][count]=fun(i+1,count);
		 return check[i+1][count];
	}
		
	else{
		visit[e[i].a] = 1;
		visit[e[i].b] = 1;
		count=count+e[i].a+e[i].b;
		if(check[i+1][count]==NIL){
			
		check[i+1][count] = fun(i+1,count);
		
		}
		int bb = check[i+1][count];
		visit[e[i].a] = 0;
		visit[e[i].b] = 0;
		count= count-(e[i].a+e[i].b);
			if(check[i+1][count]==NIL){

				check[i+1][count] = fun(i+1,count);

			}
		int aa=check[i+1][count];
		return aa||bb;
	}	
}



int main(){
	
	int t;
	cin>>t;
	while(t--){
		
		memset(visit,0,sizeof(visit));
		memset(check,NIL,sizeof(check));
		map< pair<int,int>, bool> Map;
		cin>>n>>m;
		nn=(n*(n+1))/2;
		int c_m; 
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
		if(fun(1,0))
			cout<<"YES\n";
		else
			cout<<"NO\n";		
	}	
	}
	

