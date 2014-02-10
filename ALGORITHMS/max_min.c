#include<stdio.h>
#include<stdlib.h>
int i,max,min;
int b[2],c[2];
 ff(int a[],int p,int n)
{int q;
q=(p+n)/2;
    if (p<n&&q!=p)
   {
   ff(a,p,q);
   mino(a,p,q);
   ff(a,q+1,n);
   mini(a,q+1,n);
   comp();
}
}
mino(int a[],int p,int q)
{
    i++;
    if(a[p]>a[q])
    {b[1]=a[p];
b[0]=a[q];}
else{
    b[1]=a[q];
b[0]=a[p];
}
}
mini(int a[],int p,int q)
{i++;
    if(a[p]>a[q])
    {c[1]=a[p];
c[0]=a[q];}
else{
    c[1]=a[q];
c[0]=a[p];
}
}
comp()
{i=i+2;
    if(c[1]>b[1])
    max=c[1];
    else
    max=b[1];
    if(b[0]<c[0])
    min=b[0];
   else
    min=c[0];
}
main()
{
    int a[]={22,20,99,1,101};//22 is dummy
    ff(a,1,4);
printf("the min is %d,max is %d,itt %d",min,max,i);
}
