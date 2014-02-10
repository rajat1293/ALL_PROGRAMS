#include<stdio.h>
#include<limits.h>
int main()
{
	int i,as[12],sa[12],flag=0,min=0,max,sum=0,n;
	printf("enter teh size of array\n");
	scanf("%d",&n);
	printf("enter the array\n");
	for(i=0;i<n;i++)
	scanf("%d",&sa[i]);
	max=0;
	for(i=0;i<n;i++)
	as[i]=-sa[i];
	for(i=0;i<n;i++)
	{
	sum=sum+as[i];
	if(sum<0)
	sum=0;
	if(max<sum)
	{max=sum;
	flag=1;}			
	}
	if(flag)
	{
	printf("%d",-max);
	}
	else
	{
		min=sa[0];
		for(i=1;i<n;i++)
		{
			if(min>sa[i])
			min=sa[i];
        }
        printf("%d",min);
   }
   return 0;
}
   



