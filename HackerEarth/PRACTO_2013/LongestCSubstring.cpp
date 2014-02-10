#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int arr[100][100]={0};
	char as[20],bs[20];
	cin>>as>>bs;
	int a=strlen(as)-1;
	int b=strlen(bs)-1;
	for(int i=0;i<=a;i++)
	{
		for(int j=0;j<=b;j++)
		{
			if(as[i]==as[j])
			{
				arr[i+1][j+1]=1+arr[i][j];
			}
			else
			{
				arr[i+1][j+1]=arr[i][j];
			}
			cout<<arr[i+1][j+1]<<" ";
		}
		cout<<endl;
	}
}
