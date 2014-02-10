#include<stdio.h>
#include<iostream>
using namespace std;
int x[50];
void perm(int*,int ,int);
void derm(int *a,int index,int n)
{
	int j=1;
	int a1[40];
	for(int i=1;i<=n;i++)
	{
		if(x[i])
		a1[j++]=a[i];
	}
	perm(a,index,n);
}
	
void select(int * a,int index,int i,int n)
{
	if(i==2&&index==n+1)
	derm(a,1,n);
	else if(index==n+1)
	return;
	else
{
	
	x[index]=0;
	select(a,index+1,i,n);
	x[index]=1;
	select(a,index+1,i+1,n);	
}
}
void swap(int *a ,int i,int j)
{
	int t;
	t=a[i];
	a[i]=a[j];
	a[j]=t;
}
void print(int *a,int n)
{
	
	int p=0,i;
	for( i=1;i<=n;i++)
{
	//	cout<<"1";
	if(x[i]&&p>a[i])
{
		break;
		
}
	else if(x[i])
	p=a[i];
}
		if(i==n+1)
{
	for(int j=1;j<=n;j++)
		if(x[j])
    	cout<<a[j]<<" ";
    	cout<<endl;
}

}
void perm(int *a,int i,int n)
{
//	if(x[i])
{
	if(i==n+1)
	print(a,n);
	for(int j=i;j<=n;j++)
{
		

		swap(a,i,j);
		perm(a,i+1,n);
		swap(a,i,j);

}
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
		select(arr,1,0,n);
}
}
