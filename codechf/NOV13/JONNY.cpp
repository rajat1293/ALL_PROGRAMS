#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int>& a,int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int main()
{
	int t;
	cin>>t;
	vector<int> arr(102);
	while(t--)
	{
		int n,k,i=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>arr[i];
		cin>>k;
		int pivot=arr[k];
		swap(arr,k,n);
		for(int j=1;j<n;j++)
		if(arr[j]<pivot)
		{
			i+=1;
			swap(arr,i,j);
		}
		cout<<i+1<<endl;
	}
	return 0;
}
	
	
	
