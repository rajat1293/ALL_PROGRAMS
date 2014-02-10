#include<stdio.h>
char recc(char p,char q,char r,int n)
{
     if(n>0)
    { recc(p,r,q,n-1);
     printf("block no%d is moved from %c-->>  %c\n",n,p,q);
     recc(r,q,p,n-1);
     }
}
int  main()
{    
int n;
char p='S',q='D',r='A';
     printf("enter the no of blocks");
     scanf("%d",&n);
     recc(p,q,r,n);
     getch();
     }
     
