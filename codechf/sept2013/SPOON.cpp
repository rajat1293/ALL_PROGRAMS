//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
#include<iostream>
using namespace std;
//////////////
long long binary(long long a[],long long k, long long low,long long high)
{
                long long mid,l;
                mid = (low+high)/2;
                if (low>high)
                return (low);
                else if(a[mid]==k)
                return mid;
                else if (a[mid]>k)
                {l=binary(a,k,low,mid-1);
                return l;}
                else {l=binary(a,k,mid+1,high);
                return l;}
}
//////////////


int  main()
{
	long long i,C[66];
	int t;
	scanf("%d",&t);
	C[1]=1;
	for( i=2;i<=65;i++)
	{
		if(i%2!=0)
			C[i]=(2.0/(i+2)*(i+1)*C[i-1]);
		else
			C[i]=2*C[i-1];
		}
	//	for(i=1;i<=64;i++)
	//	printf("%lld\n",C[i]);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		printf("%lld\n",binary(C,n,1,65));		
}
}


