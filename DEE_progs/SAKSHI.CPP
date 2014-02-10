#include<stdio.h>
#include<conio.h>
void main()
{
int i,arr[5],a=arr[0],b,c;
clrscr();
for(i=0;i<5;i++)
{
scanf("%d",&arr[i]);
printf("\n%d",arr[i]);
}
for(i=0;i<5;i++)
{
if(arr[i]>a)
{
b=arr[i];
}
a=arr[i];
}
for(i=0;i<5;i++)
{
if((arr[i]>a) && (arr[i]!=b))
{
c=arr[i];
}
a=arr[i];
}
printf("%d",c);
getch();
}
