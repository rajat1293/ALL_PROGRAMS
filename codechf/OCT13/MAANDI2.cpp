//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
using namespace std;
#include<vector>
#include<fstream>
#include<list>
#include<utility>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
int arr[100000000];
int binary(int a[],int k,int low,int high)
{
    int mid,l;
    mid = (low+high)/2;
    if (low>high)
    return 0;
    else if(a[mid]==k)
	return mid;
    else if (a[mid]>k)
    return binary(a,k,low,mid-1);
    else 
    return binary(a,k,mid+1,high);
}
int digi(int i)
{
	int r;
	while(i>0)
{
	r=i%10;
	i=i/10;
	if(r==4||r==7)
	return 1;
}
return 0;
}
int main()
{
	ofstream opfile;
	opfile.open("rajat.txt",ios::out);
	int keep=1;
	for(int i=1;i<=500000000;i++)
	{
		if(digi(i))
{
		opfile<<true<<",";
		//cout<<keep-1<<" "<<arr[keep-1]<<endl;
}		else
		opfile <<false <<",";
}
cout<<"done";

	int t,n;
	cin>>t;
	while(t--)
{ 
	int countt=0;
	cin>>n;
	for(int i=4;i<=n/2;i++)
{
		if(n%i==0&&digi(i))
{		countt++;
	//	cout<<i<<endl;
}
}
	if(digi(n))
{
	countt++;
//	cout<<n<<endl;
}
	cout<<countt<<endl;
}
}

