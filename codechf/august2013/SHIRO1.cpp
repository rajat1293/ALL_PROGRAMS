//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
double P[102][10002];
	int a[102];
	double p[102];
	int main()
	{
	int t;
	double max;
	scanf("%d",&t);
	while(t--)
	{
		int total=0;
		int n;
		scanf("%d",&n);
	   	for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		    total+=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%lf",&p[i]);
		    //cin>>p[i];
		      p[i]/=100.0;
		  }
		  for(int i=0;i<=n;i++)
		  P[i][0]=1;
		  for(int i=1;i<=n;i++)
		  {		  	
		  	for(int j=1;j<=total;j++)
		  	{
		  		if(a[i]>j)
			  P[i][j]=P[i-1][j]*(1-p[i])+p[i];
		  		else
		  	  P[i][j]=P[i-1][j]*(1-p[i])+P[i-1][j-a[i]]*p[i];
		//	cout<<P[i][j]<<" ";
	}
	//cout<<endl;
}
if(total%2==0)
{
	max=P[n][total/2];
	for(int i=total/2+1;i<=total;i++)
	if(max<P[n][i])
	max=P[n][i];
}
else
{
	max=P[n][(total+1)/2];
		for(int i=(total+1)/2+1;i<=total;i++)
	if(max<P[n][i])
	max=P[n][i];
}
printf("%lf\n",max);
//cout<<max<<endl;
//-------------
}
}

