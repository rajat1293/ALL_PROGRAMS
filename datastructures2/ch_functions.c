#include<stdio.h>
	extern int i;
	int fun1()
	{
		i++;
		printf("%d",i);
		return 0;
	}
	int fun2()
	{
		i--;
		printf("\n%d",i);
		return 0;
		
	}

