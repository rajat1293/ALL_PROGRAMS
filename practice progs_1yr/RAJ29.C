#include<stdio.h>
#include<conio.h>
void main()
{
int arr[]={23,45,67,87,89};
int k,i;
k=arr[0];
clrscr();
for (i=1;i<5;i++)
{
if(k>arr[i])
k=arr[i];
}
printf("%d",k);
getch();
}
