#include<stdio.h>
#include<stdlib.h>
void main()
{
int a,b,i,j,k=1;
printf("enter the no of days in the monthe");
scanf("%d",&a);
printf("entre the the first day sun =1,sat =7");
scanf("%d",&b);
printf("sun\tmon\ttue\twed\tthurs\tfri\tsat\n");
for (i=1;i<b;i++)
{
printf("\t");
}
for(j=b;j<=7;j++)
{
printf("%d\t",k);

if(j==7)
{
j=0;
printf("\n");
}
if(k==a)
break;
k++;
}
}
