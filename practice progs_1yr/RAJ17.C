#include<stdio.h>
#include<conio.h>
void main()
{
int k=0,i;
clrscr();
for(i=2;i<100;i++)
{
if(i%2!=0&&i%3!=0&&i%5!=0)
k=k+1;
}
printf("the total numbers are %d",k);
getch();
}