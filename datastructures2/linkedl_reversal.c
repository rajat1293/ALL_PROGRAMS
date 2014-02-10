#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node {
       int info;
       struct node *link;
       };

   main()
   {
         struct node *start=NULL;
         int choice,data,item,pos;
                        int i,n;
               printf("enter the no of nodes\n");
               scanf("%d",&n);
               start=NULL;
               printf("enter the element\n");
                 scanf("%d",&data);
                 struct node *tmp,*p;
                 tmp=(struct node*)malloc(sizeof(struct node));
                 tmp->info=data;
                 tmp->link=start;
                 start =tmp;
                 p=start;
                 for(i=2;i<=n;i++)
                 { printf("enter the element\n");
                 scanf("%d",&data);
                tmp=(struct node*)malloc(sizeof(struct node));
                tmp->info=data;
                 p->link=tmp;
                 p=p->link;
                 tmp->link=NULL;
                 }
                    if(start==NULL)
                    {printf("list is empty\n");
                    exit(1);
                    }
                    p=start;
                    printf("list is:\n");
                    while(p!=NULL)
                    {
                     printf("%d\n",p->info);
                     p=p->link;
                               }
                               printf("\nthe revesed  is\n");
               struct node *prev,*ptr,*next;
               prev=NULL;
               ptr=start;
               while(ptr!=NULL)
               {
               next=ptr->link;
               ptr->link=prev;
               prev=ptr;
               ptr=next;
               }
               start=prev;
               p=start;
               while(p!=NULL)
                    {
                     printf("%d\n",p->info);
                     p=p->link;
                               }

               }





