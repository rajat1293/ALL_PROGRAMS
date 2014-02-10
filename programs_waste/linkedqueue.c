#include<stdio.h>
#include<conio.h>
typedef struct node_type
{
      int data;
      struct node_type *link;
}node;
typedef node *list;
list rear=NULL,front,temp;
int p,n;
add()
{
      scanf("%d",&n);
      rear->data=n;
     temp=(list)malloc(sizeof(node));
      rear->link=temp;
       rear=temp;
      return;
}
int del()
{
      if(!rear)
      return -1;
      p=rear->data;
      rear=rear->link;
      free(front);
      front=rear;
      return p;
}
main()
{
      int t;
    //freopen("sam.txt","r",stdin);
    char ch;
     printf("Add:\n");
     scanf("%d",&t);
     front=(list)malloc(sizeof(node));
     front->data=t;
      rear=(list)malloc(sizeof(node));
      front->link=rear;
      fflush(stdin);
    printf("y/n"); 
    scanf("%c",&ch);
   //printf("%d",front->data);    
    do
    {
    add();
    fflush(stdin);
    printf("y/n"); 
    scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
    rear->link=NULL;
     rear=front;
     while(rear->link)
     {
                printf("  %d  ",rear->data);
               rear=rear->link;  
     }
     printf("\nDelete:\n");
     rear=front;
     do
     {
     p=del();
     printf("%d",p);
    fflush(stdin);
     scanf("%c",&ch);
     }while(ch=='y'||ch=='Y');          
     getch();
}
