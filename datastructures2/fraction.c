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
while(1)
{
    re=a%b;
if(re==0)
return(b);
a=b;
b=re;

}
}
