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
int copyy[1003][1003];
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
	if(arr[i][j]!=copyy[i][j])
	{
		int k,l;
		countt++;
		Arr[countt].val=arr[i][j];
		Arr[countt].x1=i;
		Arr[countt].y1=j;
		for( k=i;k<=n;k++)
			if(arr[k][j]!=arr[i][j])
			break;
		for( l=j;l<=n;l++)
			if(arr[i][l]!=arr[i][j])
			break;
			k--;
			l--;
			if((k-i)>(l-j))	
		{
			Arr[countt].x2=k;
			Arr[countt].y2=j;
			for(int k1=i;k1<=k;k1++)
			copyy[k1][j]=arr[i][j];	
		}
			else	
		{
			Arr[countt].y2=l;
			Arr[countt].x2=i;
			for(int l1=j;l1<=l;l1++)
			copyy[i][l1]=arr[i][j];

		}
			
				}
	cout<<countt<<endl;
	sort(Arr+1,Arr+countt+1,aaa());	
	for(int i=1;i<=countt;i++)
	cout<<Arr[i].val<<" "<<Arr[i].x1<<" "<<Arr[i].x2<<" "<<Arr[i].y1<<" "<<Arr[i].y2<<endl;
	
	
}
