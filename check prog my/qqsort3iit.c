#include<stdio.h>
#include<conio.h>
qrsort(int a[],int p,int r)
{
           
   int q;
   if(p<r)
   {                  
q=part(a,p,r);
qrsort(a,p,q);
qrsort(a,q+1,r);
}}
part(int a[],int p,int r)
{
         int i=p,j=r,x=a[r],t;
         while(1)
         {
          while(a[j]>x)
          j--;
          while(a[i]<x) i++ ;     
           if(i<j)
             {t=a[j];
             a[j]=a[i];
             a[i]=t;
             }
             else     
           return j;
  
     }   
}
int main()
{int a[8]={17,12,6,19,23,8,5,10},r=8,i;

printf("the arry is\n");
for (i=0;i<8;i++)
{
    printf("%d\n",a[i]);
}
qrsort(a,0,7);
printf("the sorts array is\t");
for (i=0;i<8;i++)
{
    printf("%d\t",a[i]);
}
getch();
}
