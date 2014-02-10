#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fp;
    struct{
    char name[8];
    int age;
    float salary;
    }e;
    char ano='y';
    fp=fopen("employee1.DAT","w");
    if(!fp)
    {
        printf("cannot open file\n");
        exit(2);
    }
    while(ano=='y')
    {
        printf("enter the name ,age and salary\n");
        scanf("%s%d%f",e.name,&e.age,&e.salary);
        fprintf(fp,"%s %d %f ",e.name,e.age,e.salary);

        printf("another record y/n");
        fflush(stdin);
        ano=getche();

    }}
