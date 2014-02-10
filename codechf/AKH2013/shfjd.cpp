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
#include<map>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
	map<int,bool> l;
	map<int,bool> m;
	long long  n,s=0,h=0;
	long long a,b;
	scanf("%lld",&n);
	//cin>>n;
	for(int i=1;i<=n;i++)
{
		scanf("%lld%lld",&a,&b);
		//cin>>a>>b;
		if(l[a]==false)
{
		l[a]=true;
		s++;
}
		if(m[b]==false)
{
		  h++;
		  m[b]=true;
}
}
//		cout<<(s+1)*(h+1)<<endl;
	    printf("%lld\n",(long long)(s+1)*(h+1));
}
}

