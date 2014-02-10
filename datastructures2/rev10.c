#include<stdio.h>
#include<conio.h> 
int abb(int o)
{
    int r,rev=0;
    while(o>0)
{
    r=o%10;
    o=o/10;
    rev=rev*10+r;
}
return (rev);
}
main()
{
      int k,i,p;
      for(i=100;i<=999;i++)
     { k=abb(i);
     p=2*i;
      if(k==p)
      printf("%d\n",i);
      }
      getch();
      }
