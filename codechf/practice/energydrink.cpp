#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<fstream>
#include<iomanip>
#include<bitset>
#include<deque>
#include<queue>
#include<string>
#include<map>
#include<cstring>
#include<sstream>
#include<cmath>
using namespace std;
#define gc getchar//_unlocked
 
 
void scanint(int &x)
{
register int c = gc();
x = 0;
for(;(c<48 || c>57);c = gc());
for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int a[500];
 
 
void recurse(int start,int end,int count,int &min)
{
int i;
if(start>end)
return;
 
if(start==end)
{
if(count<min)
min=count;
}
 
for(i=1;i<=a[start];i++)
recurse(start+i,end,count+1,min);
}
 
int main()
{
int min=10000;
 
int n,i,t,x,y,flag;
scanint(t);
while(t--)
{
min=100000;
scanint(n);
 
for(i=0;i<n;i++)
scanint(a[i]);
 
recurse(0,n-1,0,min);
cout<<min<<"\n";
 
 
}
return 0;
}