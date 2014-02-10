#include<stdio.h>
#include<stdlib.h>
 swap(int*,int*);
void main()
{
int a,b;
printf("enter the two numbers a and b\n");
scanf("%d%d",&a,&b);
printf("a=%d b=%d\n",a,b);
 swap(&a,&b);
printf("a=%d b=%d",a,b);
}
 swap(int *x,int*y)
{
int c;
c=*x;
*x=*y;
*y=c;
}
