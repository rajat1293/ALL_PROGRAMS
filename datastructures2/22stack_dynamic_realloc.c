#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
main()
{
	
      int i,n,*stack,top=-1,item,*kk;
      printf("enter the size of stack");
      scanf("%d",&n);
      stack=(int*)malloc(n*sizeof(int));
      stack=(int*)realloc(stack,2*n*sizeof(int));
            for (i=0;i<(n+n);i++)
     {
	  printf("\nenter element");
      scanf("%d",&item);
      stack[++top]=item;
      }
      printf("memory %d",sizeof(*stack)*2*n);
     for(i=0;i<n+n;i++)
     printf("\n%d", stack[i]);
  //    getch();
      }
      
