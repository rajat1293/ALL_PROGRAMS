#include<stdio.h>
#include<math.h>
int fib(int n)
{int k;
	if(n==1||n==2)
	{//printf("1  ");
	return 1;}
	else
{	k=fib(n-1)+fib(n-2);
	return k;	
}}
void bin(int a)
{
	int c=0,r,i=0,k=0;
	while(a)
	{
		r=a%2;
		c=c*pow(10,i)+r;
		if(r==1)
		k++;
		a=a/2;
		i++;

	}	
	printf("%d\n",k);
	printf("%d\n",c);
}
int main()
{
	int n,i,k;
	scanf("%d",&i);
k=	fib(i+1);
printf("\n%d",k);
	scanf("%d",&n);	
bin(n);

}


