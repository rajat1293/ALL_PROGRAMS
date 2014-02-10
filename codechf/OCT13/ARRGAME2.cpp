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
long long poww(int n,int m) 
{ 
  	if(m==0) return (1);
   	long long x=poww (n,m/2);
    if(m%2==0) return (x*x); 
	else return (((x*x))*n) ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
{
	int j;
	int n,countt=0,a[100004],b[100004],index[100004];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
{
	scanf("%d",&a[i]);
	if(a[i]==2)
	a[i]=4;
	else if(a[i]==1)
	a[i]=1000000009;		
}
	for(int i=1;i<=n;i++)
{
	scanf("%d",&b[i]);
	if(b[i]==2)
	b[i]=4;
	else if(b[i]==1)
	b[i]=1000000009;		
}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
{
	for( j=1;j<=n;j++)
{	
	if(a[i]<b[j])
{
	index[i]=n-j+1;
	break;
}
}
	if(j==n+1)
	index[i]=0;
}
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(6);
	 for(int i=1;i<=n;i++)
		countt+=index[i];
	float d=(float)countt/n;
	cout<<d<<endl;
}
}


