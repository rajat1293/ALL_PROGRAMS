#include<stdio.h>
#include<conio.h>
void main()
{
 int a,c,s=0;
clrscr();
printf("enter a number");
scanf("%d",&a);
do
{
c=a%10;
a=a/10;
s+=c;
}
while(a!=0);
printf("sum of digits is %d",s);
getch();
}