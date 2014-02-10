#include<stdio.h>
#include<math.h>
#define DISP(f,x) printf("f(%g)=%g\n",x,f(x));
void main()
{
int a;
float b,c,d,e;
printf("1.for square root\n2.for cosine\n3.for sine\n4.logarithmic\n");
scanf("%d",&a);
switch(a)
{
case 1:
printf("enter the no for square root");
scanf("%f",&b);
DISP(sqrt,b)
break;
case 2:
printf("entre the angle in radians");
scanf("%f",&c);
DISP(cos,c)
break;
case 3:
printf("enter the angle in radians");
scanf("%f",&d);
DISP(sin,d)
break;
case 4:
printf("for log enter value");
scanf("%f",&e);
DISP(log,e)
break;
default:
printf("invalid ");
}}

