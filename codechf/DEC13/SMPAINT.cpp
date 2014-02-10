#include<iostream>
#include<algorithm>
using namespace std;
struct aaa
{
	int val;
	int x1,x2,y1,y2;
bool operator () (const aaa & a ,const aaa &b)
{
	return a.val<b.val;
}	
};
aaa Arr[1000004];
int arr[1003][1003];
int main()
{
	int n;
	cin>>n;
	int countt=0;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	cin>>arr[i][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(arr[i][j]!=0)
	{
		countt++;
		Arr[countt].val=arr[i][j];
		Arr[countt].x1=i;
		Arr[countt].x2=i;
		Arr[countt].y1=j;
		Arr[countt].y2=j;
	}
	cout<<countt<<endl;
	sort(Arr+1,Arr+countt+1,aaa());	
	for(int i=1;i<=countt;i++)
	cout<<Arr[i].val<<" "<<Arr[i].x1<<" "<<Arr[i].x2<<" "<<Arr[i].y1<<" "<<Arr[i].y2<<endl;
	
	
}
