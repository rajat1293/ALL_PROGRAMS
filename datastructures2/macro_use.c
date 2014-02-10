#include<stdio.h>
#include<stdlib.h>
int x,y=0;
#define x (4+y)
#define y (2*x)
void main()
{
printf("%d",x);
}
