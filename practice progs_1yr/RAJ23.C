#include<stdio.h>
#include<conio.h>
void ap(int,int,int,float*,float*);
void main()
{

int a,b,c;
float av,per;
clrscr();
printf("enter the marks in three subjects");
scanf("%d%d%d",&a,&b,&c);
ap(a,b,c,&av,&per);
printf("average=%f and percentage =%f",av,per);
getch();
}
void ap(int a,int b, int c,float *x,float *y)
{
*x= ( a+b+c)/3.0;
*y=(a+b+c)/3.0;
}