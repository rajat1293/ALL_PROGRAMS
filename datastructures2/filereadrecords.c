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
    fp=fopen("employee1.DAT","r");
    if(!fp)
    {
        printf("cannot open file\n");
        exit(2);
    }
    while(fscanf(fp,"%s%d%f",e.name,&e.age,&e.salary)!=EOF)
    printf("\n%s %d %f",e.name,e.age,e.salary);
    fclose(fp);
}
