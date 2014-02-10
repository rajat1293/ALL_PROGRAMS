#include<stdio.h>
#include<stdlib.h>
struct node {
       int info;
       struct node *link;
       };
	 struct node *create(struct node *start);
 	 struct node *addpos(struct node *,int data ,int pos);
     struct node *addf(struct node* ,int data,int item);
     void display(struct node*);
	 struct   node   *reverse(struct node* start);
   main()
   {
         struct node *start=NULL;
         printf("%d",start);
         int choice,data,item,pos;
        while(1)
         {
                 printf("\n1.create\n");
                 printf("2.add at position\n");
                 printf("3.after a node\n");
                 printf("4.display\n");
                 printf("5.reverse\n");
                 printf("enter choice\n");
                 scanf("%d",&choice);
        switch(choice)
        {
    case 1 :
    start=create(start);
             break;
         case 2:
         printf("enter elemant");
         scanf("%d",&data);
         printf("pos to insert");

         scanf("%d",&pos);
         start=addpos(start, data, pos);

         break;
        case 3:
        printf("enter elemant");
         scanf("%d",&data);
         printf("element after which to insert\n");
         scanf("%d",&item);
         start=addf(start,data,item);
        break;
        case 4:
        display(start);
        break;
        case 5:
        start=reverse(start);
        break;
       default:
               printf("wrong choice exiting.....\n");
               exit(1);
               }
               }}
               struct node *create(struct node *start)
               {
               int i,n,data;
               printf("enter the no of nodes\n");
               scanf("%d",&n);
               start=NULL;
               if(n==0)
               return start;
               printf("enter the element\n");
                 scanf("%d",&data);
                 struct node *tmp;
                 tmp=(struct node*)malloc(sizeof(struct node));
                 tmp->info=data;
                 tmp->link=start;
                 start =tmp;
                 for(i=2;i<=n;i++)
                 { printf("enter the element\n");
                 scanf("%d",&data);
                struct node  *p,*tmp;
                tmp=(struct node*)malloc(sizeof(struct node));
                tmp->info=data;
                p=start;
                while(p->link!=NULL)
                 p=p->link;
                 p->link=tmp;
                 tmp->link=NULL;
                 }
                 return start;
}

    struct node *addpos(struct node *start,int data,int pos)
    {

        struct node *tmp,*p;
           int i;
           tmp=(struct node*)malloc(sizeof(struct node));
           tmp->info=data;
           if(pos==1)
           {
               tmp->link=start;
               start=tmp;
               return start;

           }
        p=start;
        for(i=1;(i<pos-1)&&(p!=NULL);i++)
        p=p->link;
        if(p==NULL)
        printf("\nless than %d elements\n",pos);
        else
        {tmp->link=p->link;
        p->link=tmp;
        }
        return start;
    }

struct node *addf(struct node* start,int data,int item)
{
    struct node *tmp,*p;
    p=start;
    while(p!=NULL)
    {
        if(p->info==item)
        {
           tmp=(struct node*)malloc(sizeof(struct node));
           tmp->info=data;
           tmp->link=p->link;
           p->link=tmp;
           return start;
        }
        p=p->link;
    }
printf("\nnot here\n");
return start;
}
void display(struct node* start)
{struct node *p;
p=start;
    while(p!=NULL)
    {
       printf("%d\n",p->info);
        p=p->link;
    }
}
struct node* reverse(struct node* start)
{
   struct node *p,*k,*n;
   p=start;
   k=NULL;
   while(p!=NULL)
   {
       n=p->link;
       p->link=k;
       k=p;
       p=n;
   }
   start=k;
   return start;
   }




