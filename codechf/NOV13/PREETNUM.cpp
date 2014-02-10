#include<iostream>
#include<stdio.h>
#include<math.h>
#include<map>
using namespace std;
bool arr[1000001];
void seive()
{
	arr[1]=true;
	int i,n,j,t;
	int k=sqrt(1000001);
	for(i=3;i<=k;i+=2)
{
		if(!arr[i])
		for(j=i*i;j<1000001;j=j+i*2)
		arr[j]=true;
}
for(i=4;i<1000001;i+=2)
{
	arr[i]=true;
}
}
int main()
{
	int t;
	seive();
	cin>>t;
	while(t--)
{
		int k=0,n;
		long long L,R;
		cin>>L>>R;
	    long long t,tt;
	    for(long long i=L;i<=R;i++)
{
 		if(!arr[i])
			k++;
		tt=i;
		t=i;
 	 	n=0;
		while(tt>=2)
{
		n=n+2;
		double a= 1.0/n;
		if(!arr[n+1])
{		double d=pow(t,a);
		tt=(long long )d;
		if((tt+0.000001)>=d&&arr[tt]==0)
{
		k++;
		break;			 
}
				
}	
}
}
		cout<<k<<endl;
}
}
