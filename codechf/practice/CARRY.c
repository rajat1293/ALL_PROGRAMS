#include<stdio.h>
int main()
{
long long int a,b;
	scanf("%lld%lld",&a,&b);
	while(a || b)
	{ int c,k,r1,r2,flag;
	c=0;flag=0;
		while(a && b)
		{
			r1=a%10;
			r2=b%10;
			if(flag==1)
		{
			k=r1+r2+1;
			flag=0;}
			else 
			k=r1+r2;	
			a=a/10;
			b=b/10;
			if(k>9)
			{c++;
			flag=1;}
			
		}
		if(c==0)
		printf("No carry operation.\n");
		else if(c==1)
		printf("%d carry operation.\n",c);
		else
		printf("%d carry operations. \n",c);
		scanf("%lld%lld",&a,&b);
	}
	return 0;
}
