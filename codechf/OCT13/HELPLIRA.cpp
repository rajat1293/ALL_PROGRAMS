//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<limits.h>
#include<utility>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
int main()
{
	int n,mini,maxi;
	cin>>n;
	int  x1,x2,x3,y1,y2,y3;
	double x,y;
	double s,a,b,c,area,min,max;
	min=1000000000;
	max=0;
	for(int i=1;i<=n;i++)
{
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b=sqrt((x1-x3)*(x1-x3)+(y3-y1)*(y3-y1));
	c=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
	s=(a+b+c)/2;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
//	cout<<area;
	if(area>=max)
{
	max=area;
	maxi=i;
}
	if(area<=min)
{
	min=area;
	mini=i;
}
}
cout<<mini<<" "<<maxi<<endl;
}


