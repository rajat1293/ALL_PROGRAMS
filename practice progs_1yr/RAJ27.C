#include<stdio.h>
#include<conio.h>
void  main()
{
int i,arr[100],n,k,p;
clrscr();
printf("enter the no of elements");
scanf("%d",&n);
for (i=0;i<n;i++)
{
printf("enter the element ");
scanf("%d",&arr[i]);
}p=n+1;
for (i=0;i<p/2;i++)
{
k=arr[n-1-i];
arr[n-1-i]=arr[i];
arr[i]=k;
}
for(i=0;i<n;i++)
printf("the reverse is%d\n",arr[i]);
getch();
}