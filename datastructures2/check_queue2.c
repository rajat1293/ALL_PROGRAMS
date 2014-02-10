#include<stdio.h>
#include<stdlib.h>
#define bb 4
int front=0,rear=0;
char item;
int queue[bb];
isempty()
{
          printf("undrflw exiting....\n");
          exit(1);
          }
   isfull()
   {
       printf("overflw exitng.....\n");
       exit(1);
       }
       addq(char item)
       {
           rear=(rear+1)%bb;
         if((rear==front))
        //  (rear>=bb-1) but importtant ,no checck when no deletion
         isfull();
         queue[rear]=item;

         }
       char  deleteq()
         {
           if(front==rear)
           isempty();
           front=(front+1)%bb;
         return  queue[front];
         }
       /*  display() problem in display.. check it
         {int i;
         if(rear==front)
         isempty();
         printf("elements are\n");
             for(i=0;i<=rear;i++)
             {
              printf("%c\n",queue[i]);
         }}*/

int main()
{ int k;char i;
      while(1)
      {
              printf("1.insert\n");
               printf("2.delete\n");
              //  printf("3.dislpay all elements of queue\n");
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
                //       case 3:
                  //     display();
                    //   break;
                       case 4:
                            exit(1);
                         default:
                                  printf("wrong choice\n");
                                  }
                                  }}


