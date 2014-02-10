#include<stdio.h>
#include<conio.h>
int pow(int,int);
main()
{
int a,b,c;
clrscr();
c=pow(a,b);
printf("%d",c);
}

int pow(int x,int y)
{
int d=1,i;
printf("enter the values of x,y");
scanf("%d%d",&x,&y);
for(i=1;i<=y;i++)
d=d*x;
return(d);
}
