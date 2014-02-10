#include<stdio.h>
int *fun();
main()
{
int *j,n=12;
//int *fun();//concept is that the function now prints a garbage value after
j=fun();//the adition of printf in b/w,as the stck now changes the local variaale it is
printf("5");
printf("%d ",*j);
}
int *fun()
{
int k;
k=9;
return(&k);	
}
