#include<stdio.h>
#include<stdlib.h>
struct student
{
char name[23];
long mobileno;
char hometown[34];
int rollno;
};
void display(struct student);
void main()
{
struct student b={"rajat",94683556,"faridabad",111581};
display(b);
}
void display(struct student b)
{
printf("%s\n%ld\n%s\n%d",b.name,b.mobileno,b.hometown,b.rollno);
}






















