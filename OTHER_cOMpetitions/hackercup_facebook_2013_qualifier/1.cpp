#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		bool flag=false;
		char arr[1000][1000];
		int store1,store2;
		int n,i,j,f=0,count=0;
		cin>>n;
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		cin>>arr[i][j];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(arr[i][j]=='#')
				{
					f=1;
					count++;
					if(count==1)
					{
						store1=i;
						store2=j;
					}
				}
				else
				    break;
			}
				if(f==1)
					break;
		}
		for(i=store1;i<=store1+count-1;i++)
		{
			for(j=store2;j<=store2+count-1;j++)
			{
				if(arr[i][j]!='#')
				{
					flag=true;
					break;
				}
				else
				{
					arr[i][j]='9';
				}
			}
		}
		for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(arr[i][j]=='#')
		{
			flag=true;
			break;
		}
		if(flag)
			cout<<"NO\n";
		else 
		cout<<"YES\n";
	}
}
