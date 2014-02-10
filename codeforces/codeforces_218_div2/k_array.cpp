#include<iostream>
using namespace std;
int main()
{
	int arr[102];
	int n,k,min=10000,count;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	if(n==k)
	{
		cout<<"0\n"<<endl;
	}
	for(int j=0;j<n;j+=k)
{
	int s=1;
	count=0;
    while(s<=n/k-1)
	{
	 	for(int i=0;i<=k-1;i++)
	 	{
			cout<<i+j<<" "<<(j+s*k+i)%(n)<<endl;
			if(arr[i+j]!=arr[(j+s*k+i)%(n)])
			{
				arr[i+j]=arr[(j+s*k+i)%(n)];
		      	count++;
	 		}
	 	s++;
   		}
   if(count<min)
   min=count;	
}
if(min==10000)
cout<<"0"<<endl;
else
cout<<min<<endl;
}
