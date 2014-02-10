#include<stdio.h>

/*main()
{
	extern int val=30;//this extern will work as global not here
	printf("%d",val);	
}int val=20;
*/
main()
{
	extern int val;
	val=30;//this extern will work as global not here
	printf("%d",val);
}
int val=20;
