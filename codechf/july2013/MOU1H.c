#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<string>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int arr[100]={0};
	int i,n,j,k,l,r,a[100],diff[100];
	scanf("%d",&n);
	r=n*(n-1)/2;
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
	diff[i]=a[i+1]-a[i];
}
//for(i=0;i<n;i++)
//printf("%d ",diff[i]);
	for(i=1;i<n;i++)
	{
		
	  if(arr[diff[i]]!=1)
		for(j=i+1;j<n;j++)
		{
		if(diff[i]==diff[j])
		{
			arr[diff[i]]=1;
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
return 0;
}

