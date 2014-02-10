#include<stdio.h>
#include<stdlib.h>
int capa =4;
int front=0,rear=0;
int item;
void copy(int*,int*,int*);
void display(int*);
void  isfull(int *);
 void isempty();
int addq(int,int*);
int deleteq(int*);
int main()
{
 int k;
 int i;
 int *queue;
 queue=(int*)malloc(capa*sizeof(*queue));
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
        scanf("%d",&item);
        addq(item,queue);
        break;
        case 2:
        i=  deleteq(queue);
        printf("  deleted item is %d\n",i);
        break;
        case 3:
        display(queue);
        break;
        case 4:
        exit(1);
        default:
        printf("wrong choice\n");
}
}
}


void copy(int* a,int* b,int* c)
{
    while(a!=b)
{
	printf("\n.....%d\n",*a);
	 *c=*a;
     a++;
     c++;
}
}
void isempty()
{
          printf("undrflw exiting....\n");
          exit(1);
          }
 void   isfull(int *queue)
{
   printf("\n new allocation started\n");
    int *nqueue;
    nqueue=(int*)malloc(capa*2*sizeof(*queue));
    int start=(front+1)%capa;
    if(start<2)//no wrap around
{
       copy(queue+start,queue+start+capa-1,nqueue);
}
   else
{
    copy(queue+start,queue+capa,nqueue);
    copy(queue,queue+rear+1,nqueue+capa-start);

}
   front=2*capa-1;//nqueue
   rear=capa-2;
   capa *=2;
   free(queue);
   queue=nqueue;
int i;
for(i=0;i<rear+1;i++)
printf("\n%d lkl\n",queue[i]);


}

addq(int item,int *queue)
{
       rear=(rear+1)%capa;
       if((rear==front))
        //  (rear>=bb-1) but importtant ,no checck when no deletion
       isfull(queue);
       queue[rear]=item;
}
int  deleteq(int*queue)
{
         if(front==rear)
         isempty();
         front=(front+1)%capa;
         return  queue[front];
}
void display(int *queue)
         {
		 int i;
        printf("\n%d as %d\n",rear,front);
    
		 if(rear==front)
         isempty();
         printf("elements are\n");
        for(i=0;i<rear+1;i++)
             {
              printf("%d\n",queue[i]);
         }
		 }
