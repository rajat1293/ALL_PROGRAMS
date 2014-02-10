#include<stdio.h>
main()
{
	register int val[30000];//this extern will work as global not here
	printf("%d",val);
}
