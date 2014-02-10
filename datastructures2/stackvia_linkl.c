#include<stdio.h>
#include<stdlib.h>
 struct node
{
      int data;
      struct node *link;
};
 struct node  *temp,*head=NULL;
int p,n;
push()
{
      temp=(struct node*)malloc(sizeof(struct node));
      printf("enter the  node data\n");
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
	//printf("%d%d",sizeof(*temp),sizeof(struct node));
    char ch;
     printf("Push:\n");
    do
    {
    push();
    fflush(stdin);
    printf("enter choice y/n");
    ch=getche();
    }while(ch=='y'||ch=='Y');
    temp=head;
     while(temp)
     {
                printf("  %d \n ",temp->data);
               temp=temp->link;
     }
     printf("Pop:\n");
     temp=head;
     do
     {
     p=pop();
     printf("%d",p);
    fflush(stdin);
 printf("enter choice y/n");
    ch=getche();
     }while(ch=='y'||ch=='Y');

}
