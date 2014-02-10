#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
float  c,g;
clrscr();
printf("enter the value of g");
scanf("%f",&g);
do
{
 c= pow(100-2*g-3*g*g,1/2);
 if(c-g<=.001)
 break;
 g+=.0001;

 }while (c-g>=.001);
 printf("root is %f",g);
 getch();

 }