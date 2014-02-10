#include<stdio.h>
#include<conio.h>
void swap(int *a,int *b)
{
     int temp=*a;
     *a=*b;
     *b=temp;
}
void bubblesort(int a[],int n)
{
     for(int i=0;i<n/2;i++)
     {
             for(int j=i;j<n-i-1;j++)
             {
                               if(a[j]>a[j+1])
                                              swap(a+j,a+j+1);
             }
              for(int i=0;i<n;i++)
              {
                                  printf("%d\t",a[i]);
              }
              printf("\n");
             for(int j=n-i-2;j>i;j--)
             {
                               if(a[j]<a[j-1])
                                              swap(a+j,a+j-1);
             }
             for(int i=0;i<n;i++)
             {
                                 printf("%d\t",a[i]);
             }
              printf("\n");
     }     
}
int main()
{
    int n;
    int a[100];
    printf("Enter the total number of elements=>");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&a[i]);
    }
    printf("Processing...\n\n");
    bubblesort(a,n);
    printf("\n\n\nAfter Sorting...\n\n");
    for(int i=0;i<n;i++)
    {
            printf("%d\t",a[i]);
    }
    getch();
}
