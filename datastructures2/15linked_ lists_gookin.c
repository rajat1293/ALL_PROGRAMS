#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int  main()
{
    struct jb{
           char name[25];
           struct jb *next;
           };
           char *bond[7]={"rajat","naveen","bhanu","vipul","deedanshu","vishal","nitish"};
           struct jb *f;
           struct jb *c;
           struct jb *n;
           int index=0;
           f=(struct jb *)malloc(sizeof(struct jb));
           c=f;
           while(1)
           {
                         strcpy((*c).name,bond[index]);
                         index++;
                         if(index<7)
                         {
                     n=(struct jb*)malloc(sizeof(struct jb));
                         c->next=n;
                         c=n;

                         }
                         else
                         {c->next=NULL;
                         break;
                         }
                         }
              c=f;
              index=1;
              while(c)
              {
                      printf("structure %d:",index++);
                      printf("%s\n",c->name);
                      c=(*c).next;
                      }
                      getch();
                      }



