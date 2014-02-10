#include<stdio.h>
#include<conio.h>
void main()
{ int a;
clrscr();
printf(" the leap yr bet 1000 and 2000\n");
for(a=1000;a<2000;a+=1)
{if(a%4==0&&a%100==0&&a%400==0)
printf("%d\t",a);
}
getch();
}