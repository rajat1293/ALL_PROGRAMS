#include<stdio.h>
#include<limits.h>
#include<conio.h>
void find_two_largest(int a[],int n,int *largest,int *second_largest)
{
     if(n<2) {*largest=*second_largest=0;return;}
     *largest=*second_largest=INT_MIN;
     for(int i=0;i<n;i++)
     {
             if(a[i]>*largest)
             {
                            *second_largest=*largest;
                            *largest=a[i];
             }
             else if(a[i]>*second_largest)
                             *second_largest=a[i];
     }
}
int main()
{
    int a[100];
    int n;
    int l,sl;
    printf("Enter the total number of elements=>");
    scanf("%d",&n);
    if(n>100)
             printf("Error: number of elemets must be less than 100");
    else
    {
             for(int i=0;i<n;i++)
             {
                     scanf("%d",&a[i]);
             }
             find_two_largest(a,n,&l,&sl);
             printf("largest=%d\nsecond largest=%d",l,sl);
    }
    getch();

}
