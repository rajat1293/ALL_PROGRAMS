#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 struct node  {
       int info;
       struct node *link;
       };
   struct node *create(struct node *start);

   main()
   {
         struct node *start=NULL,*p;
         int choice,data,item,pos;
         start=create(start);
        p=start;
        while(p!=NULL)
        {
                      printf("%d\n",p->info);
                      p=p->link;
                      }

}
               struct node *create(struct node *start)
               {
               int i,n,data;
               printf("enter the no of nodes\n");
               scanf("%d",&n);
               start=NULL;
               if(n==0)
               {printf("useless"+3);
               return start;}
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




