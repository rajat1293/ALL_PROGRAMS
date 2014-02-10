#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
char item;
int queue[10];
isempty()
{
          printf("undrflw\n");
          exit(1);
          }
   isfull()
   {
       printf("overflw\n");
       }
       addq(char item)
       {
         if(rear==9)
         isfull();
         queue[++rear]=item;

         }
       char  deleteq()
         {
           if(front==rear)
           isempty();
         return  queue[++front];
         }
         display()
         {int i;
         if(rear==front)
         isempty();
         printf("elements are\n");
             for(i=0;i<=rear;i++)
             {
              printf("%c\n",queue[i]);
         }}

int main()
{ int k;char i;
      while(1)
      {
              printf("1.insert\n");
               printf("2.delete\n");
                printf("3.dislpay all elements of queue\n");
                printf("4.quit\n");
                 printf("enter choice\n");
                 scanf("%d",&k);
                switch(k)
                {
                   case 1:
                   fflush(stdin);
                     printf("enter element to insert\n");
                     scanf("%c",&item);
                     addq(item);
                     break;
                     case 2:
                      i=  deleteq();
                       printf("  deleted item is %c\n",i);
                       break;
                       case 3:
                       display();
                       break;
                       case 4:
                            exit(1);
                         default:
                                  printf("wrong choice\n");
                                  }
                                  }}


