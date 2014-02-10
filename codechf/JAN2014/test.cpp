#include<iostream>
using namespace std;
void rev(int * arr,int a,int n){
	int temp;
	for(int j=n,i=a;i<=j;i++,j--){
		temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}

int main()
{
	int arr[]={1,2,3,4};
	rev(arr,1,3);
	for(int i=0;i<=3;i++)
	cout<<arr[i]<<" ";
	
}
