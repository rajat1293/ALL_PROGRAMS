#include<stdio.h>
#include<stdlib.h>
int oo,min[1],q=8;
int b[2],c[2];
 ff(int a[],int p,int n)
{
    if (q>=2)
   {
       q=n/2;
   ff(a,p,q);
   mino(a,p,q);
   ff(a,q+1,n);
   mini(a,q+1,n);
   comp();


   }
}
mino(int a[],int p,int q)
{
    if(a[p]>a[q])
    {b[1]=a[p];
b[0]=a[q];oo++;}
else{
    b[1]=a[q];
b[0]=a[p];
oo++;}
}
mini(int a[],int p,int q)
{
    if(a[p]>a[q])
    {c[1]=a[p];
c[0]=a[q];oo++;}
else{
    c[1]=a[q];
c[0]=a[p];
oo++;}
}
comp()
{
    int j=0,k=0,i;
for(i=0;i<2;i++)
  {
      if(b[k]<c[j])
  {
      min[i]=b[k];
      k++;
  }
  else{
  min[i]=c[j];
  j++;}

}}
main()
{
    int a[]={22,24,14,4,6,1,99,43,76};//22 is dummy
    ff(a,1,8);
printf("the min is %d,second min is %d,itt %d",min[0],min[1],oo);
}
