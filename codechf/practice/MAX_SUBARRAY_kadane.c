#include<stdio.h>
#include<limits.h>
int main()
{
	int i,sa[12],max,sum=0,n;
	printf("enter teh size of array\n");
	scanf("%d",&n);
	printf("enter the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&sa[i]);
	max=INT_MIN;
	for(i=0;i<n;i++)
	{
		if(sa[i]>0)
		sum=sum+sa[i];
		else 
		sum=0;
		if(sum>max)
		max=sum;
			
	}
	printf("%d",max);
	return 0;	
}
 

