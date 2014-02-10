#include<stdio.h>
#include<conio.h>
void main()
{
int a,c,s;
clrscr();
printf("enter a number a");
scanf("%d",&a);
do
{
c=a%10;
printf("%d",c);
a=a/10;
}while(a!=0);
getch();
}