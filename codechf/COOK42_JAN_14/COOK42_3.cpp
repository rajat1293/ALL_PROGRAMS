#include<iostream>
#include<algorithm>
using namespace std;
struct gang{
	int x,y;
bool operator () (const gang & a, const gang & b){
	return a.x < b.x;
}	
};
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,x;
		cin>>n>>x;
		int friends[n+2];
		gang g[n+2];
		for(int i=1;i<=n;i++)
		{
			cin>>g[i].x>>g[i].y;
		}
		sort(g+1,g+1+n,gang());
		int index=1,j;
		for(int i=1;i<=n;i++){
			friends[index]=1;
			for(j=i+1;j<=n;j++){
				if(g[i].y>=g[j].x)
					friends[index]++;
					else
						break;
			}
			if(j==n+1)
				break;
			index++;
		}
		int countt=0;
		for(int i=1;i<=index;i++){
			if(friends[i]>=x){
				countt += 1 + friends[i] - x;
			}
		}
		cout<<countt<<endl;
	//	for(int i=1;i<=index;i++){
	//		cout<<friends[i]<<" ";
		}
	}

