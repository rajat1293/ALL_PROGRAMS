#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int x[50];
void print(int *a,int n)
{
	for(int i=1;i<=n;i++)
	if(x[i])
	cout<<a[i]<<" ";
	cout<<endl;
}
void select(int * a,int index,int i,int n)
{
	if(i==6&&index==n+1)
	print(a,n);
	else if(index==n+1)
	return;
	else
{
	
		x[index]=1;
	select(a,index+1,i+1,n);	
	x[index]=0;
	select(a,index+1,i,n);
}
}	
int main()
{
	int n;
	int arr[40];
	while(1)
{
		cin>>n;
		if(n==0)
		break;
		for(int i=1;i<=n;i++)
		cin>>arr[i];
		sort(arr+1,arr+n+1);
		select(arr,1,0,n);
}
}
