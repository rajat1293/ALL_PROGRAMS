#include<iostream>
#include<stdio.h>
using namespace std;
#define NIL -1
int funk[100][100]={NIL};
int func(int x,int y)
{
	if(funk[x][y]!=NIL)
	return funk[x][y];
	if(x==0)
	 {
	 	funk[x][y]=y+1;
	 return y+1;
	}
	else if (x>0&& y==0)
	{
		funk[x-1][1]=func(x-1,1);	
	return  funk[x-1][1];
	}
	else
{
			funk[x-1][funk[x][y-1]]	=func(x-1,func(x,y-1));	
				return funk[x-1][funk[x][y-1]]	;
}
}
int main()
{
	
	int x,y;
	cin>>x>>y;
	cout<<func(x,y);
		
}
