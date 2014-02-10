#include<stdio.h>
int fun1(int n)
{
  if(n == 1)
     return 0;
  else
     return 1 + fun1(n/2);
}
void fun2(int n)
{
  if(n == 0)
    return;
 
  fun2(n/2);
  printf("%d", n%2);
}  
main()
{int n;
	printf("enter the no\n");
	scanf("%d",&n);
printf("%d\n",fun1(n));
fun2(n);
} 
