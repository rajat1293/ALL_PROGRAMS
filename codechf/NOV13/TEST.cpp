#include<iostream>
#include<vector>
#include<math.h>
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
	int n;
	double a=1/4.0;
	int t=22;
	while(t--)
{	cin>>n;
	cout<<pow(n,a);
}
}
