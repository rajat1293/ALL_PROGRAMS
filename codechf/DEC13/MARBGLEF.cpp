#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
	vector<int> sum(1000003,0);
	unordered_map<int,int> M;
	int n;
	cin>>n;
	int Q;
	cin>>Q;
	vector<int> V(n+2);
	cin>>V[0];
	sum[0]=V[0];
	for(int i=1;i<n;i++)
	{
		cin>>V[i];
		sum[i]=V[i]+sum[i-1];
	}
	while(Q--)
	{		
		int res=0;
		char ch;
		int a,b,ans=0;
		cin>>ch>>a>>b;
		ans=sum[b]-sum[a]+V[a];
		if(ch=='S')
		{
			for(unordered_map<int,int>::iterator it=M.begin();it!=M.end();it++)
			{
				 if(it->first<=b&&it->first>=a)
				{
					ans=ans+it->second;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		if(ch=='G')
		{
			M[a]+=b;
		}
		
		else 
		{
			
			M[a]-=b;
	
		}
	}	
}
