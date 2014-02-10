#include<iostream>
using namespace std;


map<int,map<int,int> > hash;
map<int,map<int,bool> > exist;
int func(int x,int y)
{
	if(exist[x][y])
	{
		return hash[x][y];
	}
	else
	{
		long long result;
		if(x==0)
			result=y+1;
		else if (x>0&& y==0)
			result=func(x-1,1);	
		else
			result=func(x-1,func(x,y-1));

		exist[x][y]=true;
		hash[x][y]=result;
		return result;
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
		cout<<func(x,y)<<endl;
	}

}
