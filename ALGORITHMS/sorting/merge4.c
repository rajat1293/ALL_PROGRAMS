#include<stdio.h>
#include<conio.h>
#include<limits.h>
mergee(int a[],int p,int r)
{int q;
    if(p<r)
    {
        q=(p+r)/2;
        mergee(a,p,q);
        mergee(a,q+1,r);
        mersort(a,p,q,r);

}}
mersort(int a[],int p,int q,int r)
{int n1,n2,i,k,j;
   n1=q-p+1;
   n2=r-q;
   int l[n1+1],m[n2+1];
   for (i=0;i<n1;i++)
   {
       l[i]=a[p+i];
   }
   for(i=0;i<n2;i++)
   {
       m[i]=a[q+i+1];
   }

   l[n1]=INT_MAX;
   m[n2]=INT_MAX;

   i=0;
   j=0;
   for(k=p;k<=r;k++)
   {
       if(l[i]<=m[j])
       {
         a[k]=l[i];
         i++;}
         else
          {a[k]=m[j];
         j=j+1;}

       }
   }
main()
{
    int a[1000],r,i;
    printf("entr the no of elements in thts arry");
    scanf("%d",&r);
    printf("enter the elements");
    for (i=0;i<r;i++)
    {
        scanf("%d",&a[i]);
    }
    mergee(a,0,r-1);
    printf("the sorted arry is\n");
    for(i=0;i<r;i++)
    printf("%d\n",a[i]);
    getch();
}
