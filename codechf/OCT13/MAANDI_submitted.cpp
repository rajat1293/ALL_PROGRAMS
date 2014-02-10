//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<utility>
#include<map>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
int digi(int i)
{
	int r;
	while(i>0)
{
	r=i%10;
	i=i/10;
	if(r==4||r==7)
	return 1;
}
return 0;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
{ 
	map<int,bool> check;
	int countt=0;
	cin>>n;
	int i=2;
	int roo=sqrt(n);
	//----------------
	while(i<=roo)
{
	if(n%i==0)
{	
	if(digi(i))
	countt++;
	if(digi(n/i))
	countt++;
}
	i++;
}
//------------------
	if(digi(n))
{
	countt++;
}
	cout<<countt<<endl;
}
}

