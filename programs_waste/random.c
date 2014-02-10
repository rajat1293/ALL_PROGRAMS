#include<stdio.h>
#include<stdlib.h>
main()
{
    int i,b;
     srand((unsigned)time(NULL));
    for(i=0;i<5;i++)
    {
        b=rand()%100;
        printf("%d\n",b);
    }

}
