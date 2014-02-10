#include<stdio.h>
struct student
{
 int student;
 int roll;
 char name[50];
 float fee;
 }
 main()
 {
     int i,n; struct student s[50];
     printf("enter the total number of student=");
     scanf("%d",&n);
     if(n>50)
     {
       printf("invalid");
     }


     for(i=0;i<n;i++)
     {
         printf("enter roll no., name,fee");
         scanf("%d",&(s[i].roll));
         scanf("%s",&(s[i].name));
         scanf("%f",&(s[i].fee));
     }
    float total_fee;
total_fee=0;
for(i=0;i<n;i++)
{
    total_fee=total_fee+s[i].fee;}

    printf("total_fee=%f",total_fee);

 }
