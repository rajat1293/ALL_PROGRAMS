#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int i,l;
float k;
clrscr();
for(i=1;i<=50;i++)
{
k=pow(i,.5);
l=pow(i,.5);
if(k-l==0)
{
printf("perfect squares are %d\n",i);
}

}
getch();
}