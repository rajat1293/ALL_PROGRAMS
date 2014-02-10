#include<stdio.h>
#include<conio.h>
void main()
{
int a,b,c,i;
clrscr();
printf("enter the value of a and b");
scanf("%d%d",&a,&b);
for (i=1;i<=15;i++)
{
c=a+b;
printf("%d",b);
printf(" ");
a=b;
b=c;
}
getch();
}