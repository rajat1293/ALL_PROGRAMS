#include<stdio.h>
#include<stdlib.h>
main()
{
    int i,k;
     srand((unsigned)time(NULL));
    for(i=0;i<5;i++)
    {
        k=rand()%10000;
        printf("%d\n",k);
    }

}
