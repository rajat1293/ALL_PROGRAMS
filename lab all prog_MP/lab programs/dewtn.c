#include<stdio.h>
void assign(int *d)
{
     d[1]=d[0]+1;
    d[3]=d[4]-1;
    d[2]=(d[1]+d[3])/2;

}
main()
{
    int i,a[5],b[5],j;
    printf("Enter the values of a,b,c,d");
    scanf("%d%d%d%d",&a[0],&a[4],&b[0],&b[4]);
    assign(a);
    assign(b);
    printf("Avg case:\n");
    for(i=0;i<5;i++)
        printf("(%d, %d)\n",a[2],b[i]);
    for(i=0;i<5;i++)
        {
            if(i!=2)
             printf("(%d, %d)\n",a[i],b[2]);
        }
    printf("Worst case:\n");
       for(i=0;i<5;i++)
           for(j=0;j<5;j++)
           {
               printf("(%d, %d)\n",a[i],b[j]);
           }

        }
