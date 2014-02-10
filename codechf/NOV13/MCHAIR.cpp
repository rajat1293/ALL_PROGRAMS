#include<iostream>
#include<vector>
using namespace std;
#define MOD  1000000007
long long poww(int n,int m) 
{ 
  	if(m==0) return (1)%MOD;
   	long long x=poww (n,m/2);
    if(m%2==0) return (x*x)%MOD; 
	else return (((x*x)%MOD)*n) %MOD;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	int n;
	cin>>n;
	long long p=poww(2,n);
	cout<<p-1<<endl;
}
}
