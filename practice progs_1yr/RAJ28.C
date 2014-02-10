#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,k;
int arr[5]={50,40,10,30,20};
clrscr();
 for(i=0;i<5;i++)
 {
 for(j=i+1;j<5;j++)
 {
 if(arr[i]>arr[j])
 {
 k=arr[i];
 arr[i]=arr[j];
 arr[j]=k;
 }
 }
 }
 for(i=0;i<5;i++)
 printf("%d\t",arr[i]);
 getch();
}