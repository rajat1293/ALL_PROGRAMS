#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,k,j,i;
printf("enter the value of n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{ for(j=1;j<i;j++)
printf(" ");
for(k=1;k<=n+1-i;k++)
{
printf("%d",k);
}
for(k=n-i;k>=1;k--)
printf("%d",k);
printf("\n");
}
}
