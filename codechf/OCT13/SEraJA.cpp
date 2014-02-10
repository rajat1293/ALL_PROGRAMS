//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<utility>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
#define MOD 1000000007
long long poww(long long n,long long  m) 
{ 
  	if(m==0) return (1)%MOD;
   	long long x=poww (n,m/2);
    if(m%2==0) return (x*x)%MOD; 
	else return (((x*x)%MOD)*n) %MOD;
}
int main()
{

long long t;
cin>>t;
while(t--)
{
	long long n,m,q,k,a=0,b=0,c=0,d=0;
	cin>>n>>m>>q>>k;
	if(m<q)
{
	cout<<0<<endl;
	continue;
}
	a=poww(q+1,n);
	b=2*poww(q,n);
	c=poww(q-1,n);
	a=(a+c)%MOD;
	d=a-b;
	if(d<0)
	a=d+MOD;
	else
	a=a-b;
	a=a*(m-q);
	cout<<a<<endl;
}
}


