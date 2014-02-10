#include<iostream>
#include<math.h>
using namespace std;
struct arrays
{
	int arr[302][302];
};
int arr[302][302]={0};
arrays aaa[11];	
int main()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>arr[i][j];
//--------------------one to ten--------------------
for(int s=1;s<=10;s++)
{

	if(arr[1][1] == s)
		aaa[s].arr[1][1]=1;
	
	for(int j=2;j<=n;j++)
	{
		if(arr[1][j]==s)
		aaa[s].arr[1][j] = aaa[s].arr[1][j-1]+1;
		else 
		aaa[s].arr[1][j] = aaa[s].arr[1][j-1];
		if(arr[j][1]==s)
		aaa[s].arr[j][1] = aaa[s].arr[j-1][1]+1;
		else
		aaa[s].arr[j][1] = aaa[s].arr[j-1][1];
	}
	for(int i=2;i<=n;i++)
	for(int j=2;j<=n;j++)
	{
	    aaa[s].arr[i][j]= aaa[s].arr[i-1][j]+aaa[s].arr[i][j-1]-aaa[s].arr[i-1][j-1];
	    if(arr[i][j]==s)
	    	aaa[s].arr[i][j]+=1;
	    
	}
}
//--------------end one  to ten ------------------------	
/*
for(int s=1;s<=10;s++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<aaa[s].arr[i][j]<<" ";
			}
			cout<<endl;
			
		}
		cout<<endl;
		cout<<endl;
	}
*/
//----------------print-------------------
	cin>>q;
	while(q--)
	{
		int x1,y1,x2,y2,count=0;
		cin>>x1>>y1>>x2>>y2;
		for(int s=1;s<=10;s++)
		{
		if( aaa[s].arr[x2][y2]-aaa[s].arr[x1-1][y2]-aaa[s].arr[x2][y1-1]+aaa[s].arr[x1-1][y1-1]>=1)
			count++;
		}
		cout<<count<<endl;			
	}
}
