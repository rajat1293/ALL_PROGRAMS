#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int r=0,k=0;
float a,c;
clrscr();
printf("enter the number");
scanf("%d",&a);
while(a>=1)
{
c=a%10;
r=r*10+c;
a=a/10;
k=k+1;
}
a=a*pow(10,k);
if(r==a)
printf("number is palindrome");
else
printf("not a palindrome");
getch();
}