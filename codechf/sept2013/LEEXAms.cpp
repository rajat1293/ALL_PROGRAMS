//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
{	
	double p[52];
	int a[52],b[54],n;
	int a1[52]={0},A1[52]={0},b1[52]={0},B1[52]={0};
	double P[52][3];
	a[0]=b[0]=0;
	memset(P,0,sizeof(P));
	P[0][1]=0.5;
	P[0][2]=0.5;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	cin>>p[i]>>a[i]>>b[i];
	p[i]=p[i]/100.0;
//	cout<<p[i]<<endl;
}

	for(int i=1;i<=n;i++)
{
		if(a[i-1]!=a[i]&&a1[a[i]]!=1)
{		
		a1[a[i]]=1;
	//	cout<<a1[a[i]];
		P[i][1]=P[i-1][1]*p[i];
	//	cout<<P[i][1]<<endl;
}
		if(b[i-1]!=a[i]&&A1[a[i]]!=1)
{		
		A1[a[i]]=1;
		P[i][1]+=P[i-1][2]*p[i];
	//			cout<<P[i][1]<<endl;
}
		if(a[i-1]!=b[i]&&b1[b[i]]!=1)
{
		b1[b[i]]=1;
		P[i][2]=P[i-1][1]*(1-p[i]);
}
		if(b[i-1]!=b[i]&&B1[b[i]]!=1)
{
		B1[b[i]]=1;
		P[i][2]+=P[i-1][2]*(1-p[i]);
}
}
cout<<P[n][1]+P[n][2]<<endl;
}
}
