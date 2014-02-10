//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
using namespace std;
#include<stdlib.h>
#include<vector>
#include<list>
#include<utility>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
int main()
{
	int t;
	cin>>t;
	while(t--)
{
	int max=0;
	int x;
	int diff[56];
	int n,change=0,a[56],b[56];
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];			
	for(int i=1;i<=n;i++)
	change+=b[i]-a[i];
	for(int i=1;i<=n;i++)
	diff[i]=b[i]-a[i];
	for(int i=1;i<=n;i++)
	if(abs(diff[i])>max)
	max=abs(diff[i]);
	if(n==1&&change<=0)
{
	cout<<a[1]-b[1]<<endl;
	continue;
}
	else if(n==1)
{	cout<<"-1\n";	
	continue;
}
	if(n==2&&change==0)
{
	if(b[1]>=a[1])
	cout<<b[1]-a[1]<<endl;
	else
	cout<<b[2]-a[2]<<endl;
}
	else if(n==2)
	cout<<"-1\n";
	else
{
	if(change%(n-2)==0)
{
		x=change/(n-2);
		if(x<0)
		cout<<"-1\n";
		else if(x>0)
{
		int i;
		for( i=1;i<n;i++)
{	
			if(abs(diff[i])%2!=abs(diff[i+1])%2)
			break;
}	
		if(i!=n)
		cout<<"-1\n";
		else
{
		if(x<max)
		cout<<"-1\n";
		else
		cout<<x<<endl;						
}			
				
}
	//	cout<<x<<endl;
		else
{
			int i;
			for(i=1;i<=n;i++)
			if(a[i]!=b[i])
			break;
			if(i==n+1)
			cout<<"0\n";
			else
			cout<<"-1\n";			
}
}
	else
	cout<<"-1\n";
}
}
}


