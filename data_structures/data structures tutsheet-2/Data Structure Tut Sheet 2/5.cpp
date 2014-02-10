#include<stdio.h>
#include<conio.h>
int *find_middle(int a[],int n)
{
      
      
      if(n%2==1) return a+n/2;
      else return a+n/2-1;
}
int main()
{
    int a[100];
    int n;
    printf("Enter the no. of elements=> ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",a+i);
    }
    printf("middle=%d",*find_middle(a,n));
    getch();
    return 0;
}
