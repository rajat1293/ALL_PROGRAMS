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
    fp=fopen("employee.DAT","rb");
    if(!fp)
    {
        printf("cannot open file\n");
        exit(2);
    }
    while(fread(&e,sizeof(e),1,fp)==1)
    {

       printf("%s%d%f\n",e.name,e.age,e.salary);

        }
    fclose(fp);
    }
