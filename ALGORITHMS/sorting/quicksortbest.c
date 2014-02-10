#include<stdio.h>
#include<conio.h>
int qrsort(int a[],int p,int r)
{
int q ;
if(p<r)
  {

   q = patti(a,p,r);
   qrsort(a,p,q-1);
   qrsort(a,q+1,r);}
}
int patti(int a[],int p,int r)
{
     int x,i,j,t,k;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++)
        {
        if(a[j]<=x)
        {
            i=i+1;
            t=a[i];
            a[i]=a[j];
            a[j]=t;        
        }
    }
            k=a[i+1];
            a[i+1]=a[r];
            a[r]=k;
            return (i+1);

}
main()
{
    int a[7],p,r,i;
    printf("enter the no of elements in the arry");
    scanf("%d",&r);
    printf("enter tthe elements");
    for (i=0;i<r;i++)
    {
        scanf("%d",&a[i]);
    }
    qrsort(a,0,r-1);
printf("the sorted arry is\n");
for(i=0;i<r;i++)
{
    printf("%d\n",a[i]);
}
getch();
}
