#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int e,d,n,c,q,a,b;
		scanf("%d%d%d",&n,&c,&q);
		while(q--){
			scanf("%d%d",&a,&b);
		 if(a==c)
		c=b;
		else if(c==b)
		c=a;
		else
		{
			d=c-a;
			e=b-c;
			if(e>d)
			{
			c=b-d;
			a=a+d;
			b=b-d;
			}
			else 
	{			c=a+e;
	            a=a+e;
				b=b-d;	
			}
		}
		}
		printf("%d\n",c);	
	}
	return 0;	
}
