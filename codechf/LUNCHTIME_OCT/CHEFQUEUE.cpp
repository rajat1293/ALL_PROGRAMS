#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define MOD 1000000007
struct node
{
	long long index;
	long long val;
};
int main()
{
	long long fear=1;
	stack<node> St;
	vector<node> A(1000004);
	long long n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
{		
	cin>> A[i].val;
	A[i].index=i;
}
	St.push(A[0]);
	for(int i=1;i<n;i++)
	{
		while(1)
		{
			if(!St.empty())
		{
			node no=St.top();
			if(no.val>A[i].val)
			{
				St.pop();
				fear=((A[i].index-no.index+1)*fear)%MOD;
			}
			else
			{
				St.push(A[i]);
				break;
			}
			
		}
			else
			{
				St.push(A[i]);
				break;
			}
			
		}
	}	
	cout<<fear;
}
