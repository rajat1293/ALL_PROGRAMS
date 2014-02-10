#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK 3
int stack[MAX_STACK];
        int top=-1;
        void  isfull()
   {
           fprintf(stderr,"stack is full exiting....\n");
           exit(EXIT_FAILURE);
          }
  void   isempty()
     {
          printf("stack is empty...");
          exit(1);
             }

     void   push(int  item)
        {
                     if(top>=MAX_STACK-1)
                     isfull();
                     stack[++top]=item;
                     }
     int  pop()
     {
       if(top==-1)
        isempty();
      return stack[top--];
      }

       void display()
       {
            int i;
         if(top==-1)
         {
                    isempty();
                    }
                    printf("element of stack are\n");
                    for(i=top;i>=0;i--)
                    {
                      printf("%d\n",stack[i]);
                      }
                      }

     main()
     {
           int c;
           int  i;
           while(1)
           {
           printf("\n1.push\n");
           printf ("2.pop\n");
           printf ("3.display stack\n");
           printf ("4.quit\n");
           printf("enter your choice\n");
           scanf("%d",&c);
           switch(c)
           {
             case 1:
              printf("enter the element to be pushed\n");
              scanf("%d",&i);
              push(i);
              break;
              case 2:
              i=pop();
              printf("\npopped item is %d",i);
              break;
              case 3:
               display();
               break;
               case 4:
               exit(1);
               default:
                      printf("\nwrong choice\n");
                      }}
                      }


