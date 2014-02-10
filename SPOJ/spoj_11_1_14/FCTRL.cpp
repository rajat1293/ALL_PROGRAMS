#include<stdio.h>
int main()
{
long long int t,k,sum=0,n;
scanf("%lld",&t);
while(t--)
{
scanf("%lld",&n);
k=n/5;
sum=0;
while(k!=0)
{
k=n/5;
sum=sum+k;
n=n/5;
//printf("%lld",k);
}
printf("%lld",sum);
printf("\n");
}

}
