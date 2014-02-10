#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX_STACK 10
typedef struct g {
        int key;
        int k;
        }element;
        element stack[MAX_STACK];
        int top=-1;
        element item;
      void  push(element);
      element   pop();
       void   isempty();
       void  isfull();
      void  display();
     void   push(element item)
        {
                     if(top>=MAX_STACK-1)
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
           printf("stack is full exiting....\n");
           exit(1);
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
              /* linkfloat()
              {
                          float a=0,*stack;
                          stack=&a;
                          a=*stack;
                          }*/

     main()
     {
           int c;

           while(1)
           {
               printf("%d",item.k);//the stack is a structure and its elements are key and k,whn we add
           printf("\n1.push\n");//directly to stack,we are actually giving the first element of structre
           //,the value..(ie to key),all other values r zero,evn the pointers
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
                      }


