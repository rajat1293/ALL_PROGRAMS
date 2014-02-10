#include<stdio.h>
#include<iostream>
using namespace std;
int x[30];
void print(int *a,int n)
{
	for(int i=1;i<=n;i++)
	if(x[i])
	cout<<x[i]<<" ";
	else 
	cout<<"0"<<" ";
	cout<<endl;
}
void select(int * a,int index,int i,int n)
{
	if(i==6&&index==n+1)
	print(a,n);
//	perm(a,1,n);
	if(index==n+1)
	return;
//	print(a,n);
	else
	{
	
	x[index]=0;
	select(a,index+1,i,n);
	x[index]=1;
	select(a,index+1,i+1,n);	
}
}
int main()
{
	int a[20];
	select(a,1,0,7);
}
