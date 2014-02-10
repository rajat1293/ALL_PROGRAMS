#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	char d;
	scanf("%d",&t);
	scanf("%c",&d);
	while(t--)
	{
		char a[250];
		int i,c,j;
		scanf("%d",&c);
		scanf("%s",a);
	    int s=strlen(a);
		for(j=0;j<c;j++)
		{      
			for(i=j;i<s;(i=2*j+1+i))
			{printf("%c",a[i]);
			i+=(2*c-2*j-1);
			if
			(i<s)
			printf("%c",a[i]);		
			}	
		}
		printf("\n");	
	}	
return 0;	
}
