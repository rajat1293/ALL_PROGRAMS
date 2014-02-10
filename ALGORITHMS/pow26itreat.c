#include<stdio.h>
#include<conio.h>
#include<math.h>
int poww(int x,int n)
{
         int i,p,g=x,k=0;
         p=log(n)/log(2);
         for(i=1;i<=p;i++)
         {x=x*x;k++;
         }if(n%2!=0)
         x=x*g;
         printf("%d",k);
         return x;}
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
