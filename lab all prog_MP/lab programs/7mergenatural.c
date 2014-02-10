#include<stdio.h>
#include<conio.h>
copy (int a[],int c[],int e[],int p)

{int k=0,i;
     for(i=0;i<6*p;i++)
     {e[k]=a[i];
     k++;}
     for(i=0;i<6*p;i++)
     {e[k]=c[i];
     k++;
     }}
int main()
{
   int  a[40]={1,2,3,4,5,6},p,
     b[40]={7,8,9,10,11,12},
     c[40]={13,14,15,16,17,18},
     d[40]={19,20,21,22,23,24},e[40],f[40],g[40];
     p=1;
     copy(a,b,e,p);
     copy(c,d,f,p);
      p=2;
      copy(e,f,a,p);
      for(p=0;p<24;p++)
      printf("%d\n",a[p]);
      getch();
      }
     
     
