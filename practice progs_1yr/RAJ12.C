#include<stdio.h>
#include<conio.h>
void main()
{
int s,d=1;
float l=0,a,k;
clrscr();
for(a=1;a<=6;a++)
{
d=1;
for(s=1;s<=a;s++)
{
d=d*s;
}
k=a/d;
l=l+k;
}
printf("%f",l);
getch();
}