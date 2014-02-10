#include<iostream>
#include<string.h>
#include<stdio.h>
#include<map>
#include<utility>
using namespace std;
struct edge{
	int a,b;
};
int m;
int n;
int nn;
edge e[102];
int visit[103][103];
int countt[102];
//-----------------------
void fun(){
	visit[1][e[1].a] = 1;
	visit[1][e[1].b] = 1;
	countt[1]=2;
	int sisi;
	for(int i=2;i<=m;i++){
		sisi=0;
		for(int j=1;j<i;j++){		
			if(visit[j][e[i].a]!=1 && visit[j][e[i].b]!=1){
				if(countt[j]>countt[i])
				{
					sisi=j;
					countt[i]=countt[j];
				}
			}
		}
			if(sisi!=0)
			for(int k=1;k<=100;k++){
				visit[i][k]=visit[sisi][k];
			}
			countt[i]+=2;
			visit[i][e[i].a] = 1;
			visit[i][e[i].b] = 1;	
		}		
//	for(int i=1;i<=m;i++)
//	cout<<countt[i]<< " ";
//	cout<<endl;	
}
//-----------------------
int main(){
	
	int t;
	cin>>t;
	for(int i=1;i<=100;i++){
		cout<<i<<endl;
		
	}
/*	while(t--){
			
			int flag=0;
		memset(countt,0,sizeof(countt));
		memset(visit,0,sizeof(visit));
		//map< pair<int,int>, bool> Map;
		cin>>n>>m;
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
		fun();
		for(int i=1;i<=m;i++)
		if(countt[i]==n)
		{
			flag=1;
			break;
		}
		if(flag==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
		
	}*/	
	}
