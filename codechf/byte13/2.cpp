//AUTHOR ---RAJAT GAMBHIR------
//DATE 19.8.13 time 21:30hrs
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,a[100],n,hq1,hq2;
		scanf("%d%d%d",&n,&hq1,&hq2);
		for(i=1;i<=n;i++)
		{
			if(i!=hq1)
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=hq2)
			
		
