#include<stdio.h>
#include<conio.h>
int fact(int);
main()
{int n,r,a,i;
printf("to calculate the value of nCr\n");
printf("Enter the value of n & r\n");
scanf("%d%d",&n,&r);
if(n<r)
{printf("Invalid option!");
for(i=0;i<100000000;i++);
exit(1);}
a=fact(n)/(fact(r)*fact(n-r));
printf("The answer is: %d",a);
getch();}
int fact(int x)
{
    int t;
    if(x==1||x==0)
    return(1);
    t=x*fact(x-1);
    return(t);}




