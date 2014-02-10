#include<random>
#include<string.h>
#include<iostream>
using namespace std;
struct edge{
	int a,b;
};
int main(){
	int t;
	cin>>t;
	int visit[102];
	edge e[102];
	int countt[102];
	while(t--){
		int n,m;
		cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>e[i].a>>e[i].b;
	if(n%2)
	{
		cout<<"NO\n";
		continue;
	}
		int j;
	for(int i=1;i<=10000;i++){
		cout<<i<<" ";
		j=1;
		memset(countt,0,sizeof(countt));
		memset(visit,0,sizeof(visit));
		while(j<=n/2){
			int rann=rand()%m+1;
			if(countt[rann]==1);
			else
			{
				if(visit[e[rann].a]==1 ||visit[e[rann].b]==1)
					{
						break;
					} 
				visit[e[rann].a]=1;
				visit[e[rann].b]=1;
				countt[rann]=1;
				j++;
			}
		}
			if(j==n/2+1){
				
				break;
			}		
	}
		if(j==n/2+1)
		cout<<"YES\n";
		else
		cout<<"NO\n";
}
}
