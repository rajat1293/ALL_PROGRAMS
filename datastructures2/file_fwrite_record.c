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
    fp=fopen("employee.DAT","wb");
    if(!fp)
    {
        printf("cannot open file\n");
        exit(2);
    }
    while(ano=='y')
    {
        printf("enter the name ,age and salary\n");
        scanf("%s%d%f",e.name,&e.age,&e.salary);
        fwrite(&e,sizeof(e),1,fp);

        printf("another record y/n");
        fflush(stdin);
        ano=getche();

    }
    fclose(fp);
    }
