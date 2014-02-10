#include<iostream>
using namespace std;
int hcf(int a,int b)
{
	if(b==0)
	return a;
	return hcf(b,a%b);
}
int main()
{
	int a,b,count=0;
	cin>>a>>b;
	if(a==b)
	{
		cout<<"0\n";
		return 0;
	}
	int hh=hcf(a,b);
	a=a/hh;
	b=b/hh;
	while(1)
	{
		while(1)
		{
			if(a%2==0)
			{
			 	a=a/2;
				count++;
			}
			else
			break;
		}
		while(1)
		{
			if(a%3==0)
			{
			 	a=a/3;
				count++;
			}
			else
			break;
		}
		while(1)
		{
			if(a%5==0)
			{
			 	a=a/5;
				count++;
			}
			else
			break;
		}
	
		if(a!=1)
		{
			cout<<"-1\n";
			return 0;
		}	
		else 
		break;	
		}
		while(1)
	{
		while(1)
		{
			if(b%2==0)
			{
			 	b=b/2;
				count++;
			}
			else
			break;
		}
		while(1)
		{
			if(b%3==0)
			{
			 	b=b/3;
				count++;
			}
			else
			break;
		}
		while(1)
		{
			if(b%5==0)
			{
			 	b=b/5;
				count++;
			}
			else
			break;
		}
		if(b!=1)
		{
			cout<<"-1\n";
			return 0;
		}	
		else 
		break;			
		}
		cout<<count<<endl;
	}
