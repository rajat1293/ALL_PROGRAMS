/*#include<stdio.h>
#include<conio.h>
#include<math.h>
float poww(int x, long   n)
{long k;
if(n==1)
return x;
    if(n%2==0)
  {   k= poww(x,n/2);
     return k*k;
 }else 
    {
    k= poww(x,n/2);
   if(n>0)  return k*k*x;
else return (float)k*k/x;
  
 }  
main()
{
    int x=1,n; long  k;
    printf("to cal the power of a number\n");
    printf("enter the number\n ");
    scanf("%d",&x);
    printf("enter the power to be calculated\n");
    scanf("%d",&n);
  k =  poww(x,n);
    printf("\n the power is %d",k);
    getch();
    
} */
#include<stdio.h>
 
float power(float x, int y)
{
    float temp;
    if( y == 0)
       return 1;
    temp = power(x,y/2);    
    if (y%2 == 0)
        return temp*temp;
    else
    {
        if(y > 0)
            return x*temp*temp;
        else
            return (temp*temp)/x;
    }
} 
 
/* Program to test function power */
int main()
{
    float x = 3;
    int y = -2;
    printf("%f", power(x, y));
    getchar();
    return 0;
} 
