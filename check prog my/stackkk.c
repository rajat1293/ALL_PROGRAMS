#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct {
        int key;
        }element;
        element *stack;
        stack =malloc(sizeof(*stack));
        int top=-1;
        int capacity = 1;
        element item;
      void  push(element);
      element   pop();
       void   isempty();
       void  isfull();
      void  display();
     void   push(element item)
        {
                     if(top>=capacity-1)
                     isfull();
                     stack[++top]=item;
                     }
                          element  pop()
     {
       if(top==-1)
        isempty();
      return stack[top--];
      }
 void  isfull()
   {
           stack=(element*)realloc(stack,2*capacity*sizeof(element));
            capacity *=2;
          }
  void   isempty()
     {
          printf("stack is empty...");
          exit(2);
             }
       void display()
       {
            int i;
         if(top==-1)
         {
                    isempty();
                    }
                    printf("element stack are\n");
                    for(i=top;i>=0;i--)
                    {
                      printf("%d\n",stack[i]);
                      }
                      }
               linkfloat()
              {
                          float a=0,*stack;
                          stack=&a;
                          a=*stack;
                          }

     main()
     {
           int c;

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
              printf("\nenter the element to be pushed");
              scanf("%d",&item);
              push(item);
              break;
              case 2:
              item=pop();
              printf("\npopped item is %d",item);
              break;
              case 3:
               display();
               break;
               case 4:
               exit(1);
               default:
                      printf("\nwrong choice\n");
                      }}
                      getch();}


