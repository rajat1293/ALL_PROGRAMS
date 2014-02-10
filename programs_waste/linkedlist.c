#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
typedef  struct node
{
  int data;
  struct node *link;
}stru;
typedef stru *list;
main()
{
     int n;
     list head=NULL, temp;
     char ch='y';
     while(ch=='y'||ch=='Y')
     {
           temp=(list)malloc(sizeof(stru));
           scanf("%d",&n);
           temp->data=n;
            temp->link=head;
           head=temp;
           printf("y/n");
            fflush(stdin);
                       scanf("%c",&ch);

     }
     temp=head;
     while(temp!=NULL)
     {
                      printf("\n%d",temp->data);
                      temp=temp->link;
     }
     printf("\n%d",sizeof(stru));
getch();
}
