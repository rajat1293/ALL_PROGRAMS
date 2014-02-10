#include<iostream>
#include<stdio.h>
using namespace std;
#define NIL -1
//int funk[100][100]={NIL};
int func(int x,int y)
{
	if(x==0)
	 {
	return y+1;
	}
	else if (x>0&& y==0)
	{
		return func(x-1,1);	
//	return  funk[x-1][1];
	}
	else
{
		return func(x-1,func(x,y-1));	
				//return funk[x-1][funk[x][y-1]]	;
}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int x,y;
	cin>>x>>y;
	cout<<func(x,y);
}
}

