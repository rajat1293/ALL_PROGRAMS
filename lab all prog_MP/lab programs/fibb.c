#include<stdio.h>
int fibo(int n)
{
 if(n==1) return 1;
 if(n==2) return 1;
 else return fibo(n-1)+fibo(n-2);
 
}
int main()
{
    int n;
    printf("enter the term u want to print");
    scanf("%d",&n);
    printf("%d",fibo(n));
    fflush(stdin);
    getchar();
}
