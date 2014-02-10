#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
main()
{
    FILE *fp,*ft;
    struct emp{
    char name[8];
    int age;
    float salary;
    };
    struct emp e;
    char empname[9];
    long recsize;
    char ano,cho;
    fp=fopen("employee.DAT","rb+");
    if(!fp)
    {
        printf("cannot open file\n");
        exit(2);
    }
    if(!fp)
    {
        fp=fopen("employee.DAT","wb+");
        if(!fp){
        printf("cannot open");
        exit(8);}

    }
    recsize=sizeof(e);
    while(1)
    {
        gotoxy(30,10);
        printf("1.add records");
        gotoxy(30,12);
        printf("2.list records");
        gotoxy(30,14);
         printf("3.modify records");
         gotoxy(30,16);
         printf("4.delete records");
         gotoxy(30,18);
         printf("0.exit");
         gotoxy(30,20);
         printf("your choice");
         fflush(stdin);
         cho=getche();
         switch(cho)
         {
             case '1':
             ano='y';
             fseek(fp,0,SEEK_END);
             while(ano='y')
             {
                  printf("\nenter the name ,age and salary\n");
        scanf("%s%d%f",e.name,&e.age,&e.salary);
        fwrite(&e,recsize,1,fp);

        printf("add another record y/n");
        fflush(stdin);
        ano=getche();

             }

             break;
   case '2':
   ano='y';
   rewind(fp);
   while(fread(&e,recsize,1,fp)==1)
    {

       printf("%s%d%f\n",e.name,e.age,e.salary);

        }
        break;

    case '3':
    ano='y';
    while(ano=='y')
    {
        printf("enter the employee name to modify");
        scanf("%s",empname);

        rewind(fp);

     while(fread(&e,recsize,1,fp)==1)
         {
             if(strcmp(e.name,empname)==0)
             {
                 printf("\nenter the new name ,age,salary");
                 scanf("%s%d%f",e.name,&e.age,&e.salary);
                 fseek(fp,-recsize,SEEK_CUR);
                 fwrite(&e,recsize,1,fp);
             }
         }

         printf("\nmodify another record y/n");
         fflush(stdin);
         ano=getche();
         }
         break;
         case '4':
         ano='y';
         while(ano=='y')
         {
            printf("enter the name to delete");
            scanf("%s",empname);
            ft=fopen("temp.DAT","wb");
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {
               if(strcmp(e.name,empname)==0)
               continue;
               else
               fwrite(&e,recsize,1,ft);
            }
            fclose(ft);
            fclose(fp);
            remove("employee.DAT");
            rename("temp.DAT","employee.DAT");
            fp=fopen("employee.DAT","rb+");
            printf("\ndelete  another record y/n");
         fflush(stdin);
         ano=getche();
         }
         break;
         case '0':
         fclose(fp);
         exit(11);
         break;
         }
    }
}


