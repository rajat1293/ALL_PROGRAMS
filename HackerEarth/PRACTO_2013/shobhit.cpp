#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> _2pos(64);
		while(n--)
		{
			int a;
			cin>>a;
			int i=0;
			while(a)
			{
				_2pos[i]+=a&2;
				a>>=1;
				i++;
			}
		}
		long long _2pow=1;
		long long result=0;
		for(int i=0;i<64;i++)
		{
			result+=_2pow*((_2pos[i]*(_2pos[i]-1))/2);
			_2pow*=2;			
		}
		cout<<result<<endl;
	}
}
