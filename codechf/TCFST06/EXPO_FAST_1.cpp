#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
	register int c=gc();
	x=0;
	int neg=0;
	for(;((c<48||c>57)&&c!='-');c=gc());
	if(c=='-')
	{
		neg=1;c=gc();
	}
	for(;c>47&&c<58;c=gc())
	{
		x=(x<<1)+(x<<3)+c-48;
	}
		if(neg)
		x=-x;
	}
int binary(int a[],int k,int low,int high)
{
                int mid,l;
                mid = (low+high)/2;
                if (low>high)
                return (low-1);
                else if(a[mid]==k)
                return mid;
                else if (a[mid]>k)
                {l=binary(a,k,low,mid-1);
                return l;}
                else {l=binary(a,k,mid+1,high);
                return l;}
}
//-----------------------------
int main()
{
     int arr[40];
     int k=1;
     int i=1,s;
	while(1)
{	
		k=k*2;
		arr[i++]=k;
		if(k==1073741824)
		break;
}
//	for(int j=1;j<i;j++)
//	cout<<arr[j]<<" ";
	bool flag=true;
    vector<int> A(100004);
	int n,index=0,countt=1;
	scanint(n);
//	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanint(A[i]);
	//scanf("%d",&A[i]);
	A[n]=-3;
 while(flag)
{
	flag=false;
  	for(int i=1;i<=n;i++)
{	
	if(A[i]==A[i-1])
		countt++;
	else if(countt==1)
{
	A[index++]=A[i-1];
}
	else
{
	flag=true;
	while(1)
{
	s=binary(arr,countt,1,32);
	A[index++]=s+A[i-1];
	countt=countt-arr[s];
	if(countt==1)
{
	A[index++]=A[i-1];
	break;
}
	else if(countt==0)
{
	countt++;
	break;
}

}
}
}
sort(A.begin(),A.begin()+index);
A[index]=-3;
for(int i=0;i<index;i++)
//cout<<A[i]<< " ";
//cout<<endl;
n=index;
index=0;
}
//--------------------------------------------
//	cout<<n;
//	cout<<endl;
	countt=A[0];
	index=0;
	for(int i=1;i<n;i++)
{
	 countt+=(A[i]-A[i-1]-1);
}
	 cout<<countt;		
	
}

			  
