#include<stdio.h>
#include<stdlib.h>
void main()
{
int arr[6],i,j,a,key;
printf("enter six no.s\n");
for (i=0;i<6;i++)
{
scanf("%d",&arr[i]);
}
for(j=1;j<6;j++)
{
    key=arr[j];
    i=j-1;
    while(i>=0&&arr[i]>key)
    {


    arr[i+1]=arr[i];
i=i-1;
}
arr[i+1]=key;
}
for(i=0;i<6;i++)
printf("\n%d\t",arr[i]);
}
