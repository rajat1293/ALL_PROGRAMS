#include<stdio.h>
main()
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=i;j>0;j--)
        printf(" ");
        for(j=1;j<(6-i);j++)
        printf("%d",j);
        for(j=4-i;j>0;j--)
        printf("%d",j);
        printf("\n");
    }
}
