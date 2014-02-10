#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void transpose(int **a,int **b,int rows,int cols)
{
     for(int i=0;i<rows;i++)
     {
             for(int j=0;j<cols;j++)
             {
                     b[j][i]=a[i][j];
             }
     }     
}

int ** allocate(int r,int c)
{
     int **a=(int **)malloc(r*sizeof(int *));
     if(a==NULL) {return 0;}
    for(int i=0;i<r;i++)
    {
            a[i]=(int *)malloc(c*sizeof(int));
            if(a[i]==NULL) {return 0;}
    }
    return a; 
}
void deallocate(int **a,int r,int c)
{
          for(int i=0;i<r;i++)
          {
                    free(a[i]);
          }
          free(a);

}
int main()
{
    int  **a, **b;
    int r,c;
    printf("Enter the number of rows and columns => ");
    scanf("%d %d",&r,&c);
    a=allocate(r,c);
    b=allocate(c,r);
    if(a==0||b==0) {printf("Error: Memory not allocated"); getch();return -1;}
    printf("Enter the elements of Matrix \n");
    for(int i=0;i<r;i++)
    {
            for(int j=0;j<c;j++)
                   scanf("%d", &a[i][j]);
    }
    
    transpose(a,b,r,c);
    printf("Transpose\n\n");

    for(int i=0;i<c;i++)
    {
            for(int j=0;j<r;j++)
                    printf("%d\t",b[i][j]);
            printf("\n");
    }
    deallocate(a,r,c);
    deallocate(b,c,r);
    
    getch();
    
    
}
