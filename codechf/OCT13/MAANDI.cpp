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
	int countt=0;
	cin>>n;
	for(int i=4;i<=n/2;i++)
{
		if(n%i==0&&digi(i))
{		countt++;
	//	cout<<i<<endl;
}
}
	if(digi(n))
{
	countt++;
//	cout<<n<<endl;
}
	cout<<countt<<endl;
}
}

