#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<string>
#define gc getchar_unlocked
using namespace std;
void scanint(int &x)
{
	register int c=gc();
	x=0;
	int neg=0;
	for(;((c<48||c>57)&&c!='-');c=gc());
	if(c=='-')
	{
		neg=1;c=gc();
	}
	for(;c>47&&c<58;c=gc())
	{
		x=(x<<1)+(x<<3)+c-48;
	}
		if(neg)
		x=-x;
	}

int a[100006],diff[100006];
int main()
{
	int t;
	//scanf("%d",&t);
	scanint(t);
	while(t--)
	{
		map<string,int> arr;
		map<string,int> arr2;
		char str[50];
	int i,n,j,k,l,r;
	scanint(n);//scanf("%d",&n);
	r=n*(n-1)/2;
	for(i=1;i<=n;i++)
	scanint(a[i]);
	//scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
	diff[i]=a[i+1]-a[i];
	sprintf(str,"%d",diff[i]);
	arr2[str]++;
}
	for(i=1;i<n;i++)
	{
		sprintf(str,"%d",diff[i]);
	    if(arr[str]!=1&&arr2[str]>=2)
		for(j=i+1;j<n;j++)
		{
		if(diff[i]==diff[j])
		{
			arr[str]=1;
			r--;
			k=i+1;
			l=j+1;
			while(k<n&&l<n)
			{
			if(diff[k]==diff[l])
			r--;
			else 
			break;
			k++;
			l++;
			}
		}
	}
	}

printf("%d\n",r);
}
}


