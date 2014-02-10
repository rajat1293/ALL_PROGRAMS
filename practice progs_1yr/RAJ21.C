#include<stdio.h>
 main()
{
int j, i,h,l,a,b;
printf("enter the two numbers");
scanf("%d%d",&a,&b);
for(i=a;i>=1;i--)
{
if(a%i==0&&b%i==0)
{
h=i;
l=a*b/h;
printf("hcf is %d and lcm is %d",h,l);
goto j;
}
}
j:
printf("");

}
