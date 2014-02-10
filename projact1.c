#include<stdio.h>
#include<conio.h>
int toh(char source,char temp,char dest, int  n)
{
         if(n==1)
         printf("\n%c ->%c",source,dest);
         else{
              toh(source,dest,temp,n-1);
              toh(source,temp,dest,1);
              toh(temp,source,dest,n-1);
              }}
int main()
{
     typedef  int raj;
     raj n;
      char source='S',temp='A',dest='D';
      printf("enter the no of disks");
      scanf("%d",&n);
      toh(source,temp,dest,n);
      getch();
      }
      
      
