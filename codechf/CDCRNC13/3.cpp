#include<stdio.h>
int main()
{
	char a[103];
	scanf("%s",a);
	char *p;
	p=a;
	while((*p)!=0)
{
	printf("%c",(char)(((int)(*p)-7)));	
	p++;	
}
}
