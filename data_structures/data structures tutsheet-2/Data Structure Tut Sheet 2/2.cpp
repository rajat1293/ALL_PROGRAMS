#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void mult(int **a,int **b,int **c,int n)
{
     int k=0;
     for(int i=0;i<n;i++)
     {
             for(int j=0;j<n;j++)
             {
                     c[i][j]=0;
                     for(int k=0;k<n;k++)
                     {
                             c[i][j]+=a[i][k]*b[k][j];
                     }
             
             }
     }
}

void allocate(int ***a,int n)
{
     *a=new int*[n];
     if(!(*a)) 
     {   
               printf("Error allocating memory");
               getch();
               exit(1);
     }
     else
     {
         for(int i=0;i<n;i++)
         {
                 *((*a)+i)=new int[n];
                 if(!(*a)) 
                 {   
                     printf("Error allocating memory");
                     getch();
                     exit(1);
                 }
         }
     }
}
void getdata(int **a,int n)
{
     printf("Enter the elements of matrix\n");
     for(int i=0;i<n;i++)
     {
             for(int j=0;j<n;j++)
                     scanf("%d",&a[i][j]);
     }
     
}
void fre(int **a,int n)
{
     for(int i=0;i<n;i++)
     {
             delete[] a[i];
     }
     delete[] a;
}
int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    int **a;
    int **b;
    int **c;
    
    allocate(&a,n);
    allocate(&b,n);
    allocate(&c,n); 
    getdata(a,n);
    getdata(b,n);
    mult(a,b,c,n);
    for(int i=0;i<n;i++)
    {
            for(int j=0;j<n;j++)
             {
                    printf("%d\t",c[i][j]);
             }
             printf("\n");
    }
    fre(a,n);
    fre(b,n);
    fre(c,n);
    getch();
}
