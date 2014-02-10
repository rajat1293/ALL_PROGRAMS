#include<stdio.h>
#include<conio.h>
int sum(int,int);
main()
{
int a,b,c;
printf("enter the value of a,b");
scanf("%d%d",&a,&b);
c=sum(a,b);
printf("%d",c);
getch();
}

int sum(int x,int y)
{
int c;
c=x+y;
return(c);
}
