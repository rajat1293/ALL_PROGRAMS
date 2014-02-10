#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
int main()
{
	vector<int> A(100006);
	int n;
	int min=10000000,j,count=0,neg=-1;	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&A[i]);
	for(int i=n-1;i>=2;i--)
{
		if(A[i]==0)
		neg++;
		count=0;
		if(A[i]<0)
{
		neg++;
		j=i-1;
		while(j>0)
{		if(A[j]>=0)
		count++;
	
		j--;
}
		count=count+neg;
		if(count<min)
		min=count;		
}				
}
		count=neg+1;
		if(A[1]>=0)
		count++;
		if(count<min)
		min=count;
		if(A[n]<=0)
		min++;
		 cout<<min;
}
