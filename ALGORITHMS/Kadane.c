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
	max=0;
	for(i=0;i<n;i++)
	{
	sum=sum+sa[i];
	if(sum<0)
	sum=0;
	if(max<sum)
	max=sum;			
	}
	printf("%d",max);
	return 0;	
}


