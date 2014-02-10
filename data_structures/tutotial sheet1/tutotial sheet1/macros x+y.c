#include<stdio.h>
#include<stdlib.h>
int y=3;
#define x (4+y)
#define y (2*x)
void main()
{
printf("%d",y);
}
