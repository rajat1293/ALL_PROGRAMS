#include<stdio.h>
int main()
{
	int t[20],*p;
	p=t;
	(*p)++=10;
	printf("%d",t[1]);	
	return 0;
	
}
