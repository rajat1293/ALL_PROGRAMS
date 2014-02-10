#include<stdio.h>
#include<conio.h>
#include<math.h>
int poww(int x, long   n)
{if(n==1)
return x;
    if(n%2==0)
     return poww(x*x,n/2);
    return poww(x*x,n/2)*x;
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
    
}  
