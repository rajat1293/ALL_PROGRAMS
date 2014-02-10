#include<stdio.h>
int main()
{
	int k,sum=0,n;
	scanf("%d",&n);
	k=n/5;
	sum=0;
	while(k!=0)
{
	k=n/5;
	sum=sum+k;
	n=n/5;
}
printf("%d\n",sum);	
return 0;
}

