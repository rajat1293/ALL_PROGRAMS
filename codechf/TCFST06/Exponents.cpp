#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> A(100004);
	int n,countt=0,ear;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&A[i]);
	sort(A.begin(),A.begin()+n);
	int index=0;
	bool flag=true;
while(flag)
{
	flag=false;
	countt+=A[0];
	index=0;
	for(int i=1;i<n;i++)
{
	if(A[i]==A[i-1])
{
	A[index++]=A[i];
	flag=true;
}
	  else
{
	 countt+=(A[i]-A[i-1]-1);
}

}
	n=index;
}
	 cout<<countt;		
}
