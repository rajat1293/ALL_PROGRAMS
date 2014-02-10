#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x;
		char arr[40];
		char *p;
		p=arr;
		p=p+38;
		*p='\0';
		scanf("%d",&x);
		if(x%2==0)
	{	printf("0\n");
	continue;}
		else
		while(x!=2){
		if((x=(x+1)/2)%2!=0)
		*(--p)='1';
		else 
		*(--p)='2';
	}
	printf("%s\n",p);		
	}
	return 0;	
}
