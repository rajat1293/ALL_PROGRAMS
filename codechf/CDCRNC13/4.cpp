#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int sum=0;
		char a,b;
		cin>>a>>b;
		if(a=='A'&&b=='A')
		{
			cout<<"STAND\n";
			continue;
		}
		if(a=='A' )
		{
		 sum=11;
	   }
		else if(a=='J'||a=='Q'||a=='K')
		{
			sum=10;
		}
		else if(a>48&&a<=57)
		{
			sum=a-48;
		}
		else
		{
			cout<<"INVALID\n";
			continue;
		}
		if(b=='A')
		sum+=11;
		else if(b=='J'||b=='Q'||b=='K')
		{
			sum+=10;
		}
			else if(b>48&&b<=57)
		{
			sum+=b-48;
		}
		else 
		{
			cout<<"INVALID\n";
			continue;
		}
		if(sum<=11)
		cout<<"HIT\n";
		else
		cout<<"STAND\n";
		
	}
}
