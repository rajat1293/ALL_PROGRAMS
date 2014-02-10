#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define maxi 70368744177664LL
int main()
{
	int t;
	ll arr[46];
	scanf("%d",&t);
	while(t--)
{
	int countt=0;
	int k;
	int n;
	ll assign=0;
	scanf("%d",&k);
	for(int a=0;a<k;a++)
{	
	scanf("%d",&n);
	if(n==0)
	countt++;
	for(int j=0;j<n;j++)
	scanf("%lld",&arr[j]);	
	sort(arr,arr+n);
	int flag=0,j; 
	long long int i=2;
	for(j=0;j<n;j++)
{
	if(arr[j]%2==0&&(flag==0||flag==1))
{
	assign=assign+maxi;
	flag = 1;
}
	else if (arr[j]%2!=0&& (flag==0||flag == -1))
{
		assign=assign+(-maxi);
		flag = -1;
}	
	else 
	break;
}

	for(;j<n;j++)
{
	
	if(arr[j]%2==0)
	assign += maxi/i;
	else
	assign += (-maxi/i);	
	i *= 2;
}	
 	
}
	if(countt==k)
	printf("EVEN\n");
	 else if(assign>0)
	printf("EVEN\n");
	else if(assign<0)
	printf("ODD\n");
	else 
	printf("DON'T PLAY\n");	
}
}	
	
