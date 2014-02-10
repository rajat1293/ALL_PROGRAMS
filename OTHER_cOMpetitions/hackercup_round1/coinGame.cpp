#include<iostream>
#include<limits.h>
#include<math.h>
#include<fstream>
using namespace std;
int main()
{
	int t;
	cin>>t;
   freopen("rajat1.txt","w",stdout);
	for(int i=1;i<=t;i++)
	{
		int jars,coins,wins,ans=0,used,empty;
		cin>>jars>>coins>>wins;
		if(wins==0)
		{
			cout<<"Case #"<<i<<": "<<ans<<endl;
			continue;
		}
		if(jars>coins)
		{
			if(wins!=0)
			ans=jars-coins+wins;
			cout<<"Case #"<<i<<": "<<ans<<endl;
			continue;
		}
		if(jars>=wins)
		{
			ans=wins;
			cout<<"Case #"<<i<<": "<<ans<<endl;
			continue;
		}
		int j=2;
		while(1)
		{
			if(j*jars>=wins)
			{
				
				used=coins/j;
				empty=jars-used;
				if(empty<0)
				empty=0;
				ans=wins+empty;
				cout<<"Case #"<<i<<": "<<ans<<endl;
			    break;		
			}
			else
			{
			  j++;
				
			}
			
		}
		
	}
}
