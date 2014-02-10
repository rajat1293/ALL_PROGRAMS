#include<stdio.h>
#include<conio.h>
void main()
{
int i,j;
clrscr();
for(i=2;i<=100;i++)
{
    for(j=2;j<i;j++)
     {
	  if((i%j)==0)
	  break;
     }
if(j==i)
printf("%d is a prime no\n",i);
}
getch();
}

