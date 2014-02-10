#include<iostream>
using namespace std;
int main()
{
	int n,c;
	cin>>n>>c;
	int arr[n+2];
	int diff[n+2];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=1;i<=n;i++)
		diff[i]=0;
	for(int i=1;i<n;i++)
	  diff[i]= arr[i]-arr[i+1];
	  int max=-1;
	  //for(int i=1;i<n;i++)
	// cout<<diff[i]<<" ";
	
	for(int i=1;i<n;i++)	
	if(diff[i]>max){
		max= diff[i];
	}
	if(max-c>=0)
	cout<<max - c<<endl;
	else 
	cout<<"0\n";
}
