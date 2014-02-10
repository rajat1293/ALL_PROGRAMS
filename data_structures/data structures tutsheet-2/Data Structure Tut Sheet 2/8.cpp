#include<stdio.h>
#include<conio.h>

bool search(int a[],int n,int key)
{
     for(int i=0;i<n;i++)
     {
             if(*(a+i)==key) return true;
     }
     return false;
}
int main()
{
    int a[100];
    int n;
    printf("Enter the number of elements=> ");
    scanf("%d",&n);
    printf("Enter the elements=> ");
    for(int i=0;i<n;i++)
    {
             scanf("%d",&a[i]);
    }
    int x;
    printf("Enter the element to search for =>");
    scanf("%d",&x);
    printf("%s",search(a,n,x)?"TRUE":"FALSE");
    getch();
    
}
