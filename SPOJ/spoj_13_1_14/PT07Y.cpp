#include<iostream>
#include<list>
#include<vector>
using namespace std;
int flag = 0;
void dfs(vector<list<int> > &graph,int i,vector<int> &isVisited)
{

	isVisited[i]=1;
	list<int>::iterator j;

	for(j=graph[i].begin();j!=graph[i].end();j++)

	{
		//	cout<<*j;
		if(!isVisited[*j]) 
			dfs(graph,*j,isVisited);
		else
		{
			flag=1;
			return ;
		}
		
	}

}



int main()

{

	int t;

//	cin>>t;

//	while(t--)

//	{

		int n,m;

		cin>>n>>m;

		vector<list<int> > graph(n+1);

		while(m--)

		{

			int a,b;

			cin>>a>>b;

			graph[a].push_back(b);

			//graph[b].push_back(a);

		}
		vector<int> isVisited(n+1);
		for(int i=1;i<=n;i++)
		{
			if(!isVisited[i])
				dfs(graph,i,isVisited);
			if(flag==1)
			break;	
		}
		if(flag==0)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	//}
}

