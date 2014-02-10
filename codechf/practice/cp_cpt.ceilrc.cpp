#include <stdio.h>
#include<stdlib.h>
    //#include<conio.h>
    inline int input( )
    {
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
    }
int main()
{
int n,num,sum,k;
num=input();
while(num--)
{
k=2048;
n=input();
sum = 0 ;
while(n)
{
sum += n/k;
n = n % k;
k /= 2 ;
}
printf("%d\n",sum);
}
}
