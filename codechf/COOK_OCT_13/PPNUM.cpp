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
long long poww(long long n,long long m)
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
long long l1,r1,sum=0;
long long res=0,l,r;
cin>>l>>r;
 
if(l<=9&&l>=1)
{
l1=1;
}
else if(l<=99&&l>=10)
l1=2;
else if(l<=999&&l>=100)
l1=3;	
else if(l<=9999&&l>=1000)
l1=4;
else if(l<=99999&&l>=10000)
l1=5;
else if(l<=999999&&l>=100000)
l1=6;
else if(l<=9999999&&l>=1000000)
l1=7;
else if(l<=99999999&&l>=10000000)
l1=8;
else if(l<=999999999&&l>=100000000)
l1=9;
else if(l==1000000000)
l1=10;
 
if(r<=9&&r>=1)
{
r1=1;
}
 
else if(r<=99&&r>=10)
r1=2;
else if(r<=999&&r>=100)
r1=3;	
else if(r<=9999&&r>=1000)
r1=4;
else if(r<=99999&&r>=10000)
r1=5;
else if(r<=999999&&r>=100000)
r1=6;
else if(r<=9999999&&r>=1000000)
r1=7;
else if(r<=99999999&&r>=10000000)
r1=8;
else if(r<=999999999&&r>=100000000)
r1=9;
else if(r==1000000000)
r1=10;
if(l1==r1)
{
long long rg=(l1*(r-l+1));
long long sg=((l+r));
long long ss=(long long)((rg*sg))/2;
sum=(long long)(sum+ss)%MOD;
}
else
{
long long rg=((long long)l1*((poww(10,l1)-1)-l+1));
long long sg=(long long)(poww(10,l1)-1+l);
long long ss=(((rg*sg))/2);
sum=(long long)(sum+ss)%MOD;
l1++;
while(l1!=r1)
{	
long long rg=((long long)l1*((poww(10,l1)-1)-poww(10,l1-1)+1));
long long sg=(long long)(poww(10,l1)-1+poww(10,l1-1));
long long ss=((rg*sg))/2;
sum=(long long)(sum+ss)%MOD;
l1++;
}
if(l1==r1)
{
long long rg=(long long)(l1*(r-(poww(10,l1-1))+1));
long long sg=(long long)(poww(10,l1-1)+r);
long long ss=(long long)((rg*sg))/2L;
sum=(long long)(sum+ss)%MOD;
}	
}
cout<<sum<<endl;
}
}
