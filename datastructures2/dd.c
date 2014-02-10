#include<stdio.h>
#include<stdlib.h>
int cf(int,int);
 main()
{
int num,den,k;
printf("enter the num and the denominator");
scanf("%d%d",&num,&den);
k=cf(den,num);
num=num/k;
den=den/k;
printf("the fraction reduces to %d/%d",num,den);
}
int cf(int a,int b)
{
int re;
re=a%b;
while(1)
{
if(re==0)
return(re);
a=b;
b=re;
re=a%b;
}
}
