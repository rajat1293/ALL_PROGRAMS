#include<stdio.h>
int y=4;
#define y x*2
#define x y+4

main()
{

    printf("%d",y);
}
