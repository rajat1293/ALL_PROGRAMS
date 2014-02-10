#include<stdio.h>
#include<conio.h>
int binary(int a[],int k,int low,int high)
{
   int mid,l;
   mid = (low+high)/2;
   if (low>high)
   return -2;
   else if(a[mid]==k)
      return mid;
   else if (a[mid]>k)
   {l=binary(a,k,low,mid-1);
   return l;}
   else {l=binary(a,k,mid+1,high);
   return l;}
}
int main()
            {
               int a[10],n,k,i;
               printf("enter the no of elements\n");
               scanf("%d",&n);
               printf("\nenter the elements");
               for(i=0;i<n;i++)
               scanf("%d",&a[i]);
               printf("\nenter element to be searched");
               scanf("%d",&k);
              int   low=0,high=n-1,p;
               p= binary(a,k,low,high);
               if(p>=0)
                printf("%d",p+1);
                else
                printf("\"idiot, the value is not here\"");
                getch();
            }
