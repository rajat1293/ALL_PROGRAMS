#include<stdio.h>
#include<conio.h>
typedef struct node_type
{
      int data;
      struct node_type *link;
}node;
typedef node *list;
list temp,head=NULL;
int p,n;
push()
{
      temp=(list)malloc(sizeof(node));
      scanf("%d",&n);
      temp->data=n;
      temp->link=head;
      head=temp;
      return;
}
int pop()
{
      if(!temp)
      return -1;
      p=temp->data;
      temp=temp->link;
      free(head);
      head=temp;
      return p;
}
main()
{
    char ch;
     printf("Push:\n");
    do
    {
    push();
    fflush(stdin);
    printf("y/n"); 
    scanf("%c",&ch);
    }while(ch=='y'||ch=='Y');
     temp=head;
     while(temp)
     {
                printf("  %d  ",temp->data);
               temp=temp->link;  
     }
     printf("Pull:\n");
     temp=head;
     do
     {
     p=pop();
     printf("%d",p);
    fflush(stdin);
     scanf("%c",&ch);
     }while(ch=='y'||ch=='Y');          
     getch();
}
