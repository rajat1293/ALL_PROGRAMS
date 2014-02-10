#include<iostream>
using namespace std;
long long  NCR(long long n)
{
	auto j=n*(n-1)/2ll;
	return j;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		int a;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a;
		cout<<NCR(n)<<endl;		
	}
}
