#include<stdio.h>
int main()
{
	int t;
	char g;
	int s=0;
	scanf("%d",&t);
	scanf("%c",&g);
	while(t--)
	{
		fflush(stdin);
		unsigned long int n,k,c=0,r;
		s=0;
		fflush(stdin);
		scanf("%d",&n);
		k=n;
		while(1){
			c=0;
		while(n)
		{
			r=n%10;
			c=c*10+r;
			n=n/10;	
		}
		s++;
		if(c==k)
		break;
		else 
		{
		n=c+k;
		k=n;	
	    }
			
	}
	printf("%d %lu\n",(s-1),c);		
	}
	return 0;
		
}
