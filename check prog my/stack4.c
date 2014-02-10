#include<stdio.h>
#include<stdlib.h>
        int top=-1;
        int capacity=1;

       void  isfull(int*);
  int pop(int*);
  void display(int*);
  void push(int,int*);


     main()
     {
         int *stack;
stack =(int*)malloc(sizeof(int));
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
              push(i,stack);
              break;
              case 2:
              i=pop(stack);
              printf("\npopped item is %d",i);
              break;
              case 3:
               display(stack);
               break;
               case 4:
               exit(1);
               default:
                      printf("\nwrong choice\n");
                      }}
                      }
                     void  isfull(int *stack)
   {
           stack=(int*)realloc(stack,2*capacity*sizeof(*stack));
            capacity *=2;
          }
void   isempty(int *stack)
     {
          printf("stack is empty...");
          exit(1);
             }

     void   push(int  item,int *stack)
        {
                     if(top>=capacity-1)
                     isfull(stack);
                     stack[++top]=item;
                     }
     int  pop(int *stack)
     {
       if(top==-1)
        isempty(stack);
      return stack[top--];
      }

       void display(int *stack)
       {
            int i;
         if(top==-1)
         {
                    isempty(stack);
                    }
                    printf("element of stack are\n");
                    for(i=top;i>=0;i--)
                    {
                      printf("%d\n",*(stack+i));
                      }
                      }

