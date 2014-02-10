#include<stdio.h>
#include<conio.h>
float mess(int,float );
void main()
{
int a=3;
float b,c=3.8;
clrscr();
b=mess(a,c);
printf("prodct =%f",b);
getch();
}
float mess(int x,float y)
{
 float k;
 k=x*y;
 return(k);


}