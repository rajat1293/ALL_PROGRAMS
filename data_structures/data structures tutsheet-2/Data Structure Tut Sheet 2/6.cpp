#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct date
{
 int d,m,y;
};

struct student
{
       int roll_number;
       char name[100];
       date date_of_birth;
};

struct student * func(int n)
{
       struct student *p=(struct student *)malloc(n*sizeof(struct student));
       if(p==NULL) return NULL;
       for(int i=0;i<n;i++)
       {
               printf("Enter the data of student %d.\n",i);
               printf("Name=> ");
               fflush(stdin);
               gets((p+i)->name);
               printf("Roll Number=>");
               scanf("%d",&(p+i)->roll_number);
               printf("DOB=>");
               scanf("%d %*c %d %*c %d",&(p+i)->date_of_birth.d,&(p+i)->date_of_birth.m,&(p+i)->date_of_birth.y);
               printf("....\n\n");
       }
       return p;
}
int main()
{
    int n;
    printf("Enter the total number of students=> ");
    scanf("%d",&n);
    struct student *p=func(n);
    for(int i=0;i<n;i++)
    {
            printf("Roll Number=%d\n",(p+i)->roll_number);
            printf("Name       =%s\n",(p+i)->name);
            printf("DOB        =%d/%d/%d\n\n",(p+i)->date_of_birth.d,(p+i)->date_of_birth.m,(p+i)->date_of_birth.y);
    
    }
    getch();
}
