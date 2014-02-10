#include<iostream>
using namespace std;
int main()
{
	int arr[102];
	int n,k,min=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>arr[i];
	if(n==k)
	{
		cout<<"0\n"<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		int count1=0,count2=0;
		for(int j=i;j<=n;j+=k)
		{
			if(arr[j]==1)
			count1++;
			else
			count2++;		
		}
		if(count1<count2)
		min=min+count1;
		else
		min+=count2;	
	}
	
	cout<<min<<endl;
}
	
	
	
	
