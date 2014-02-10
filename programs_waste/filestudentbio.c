#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
       int roll;
       char name[100];
       char mobile[10];
       char home[20];
       int k;
}s[100];
main()
{ int i,j;
    FILE *p;
    p=fopen("student1.bio","w");

    if(p==NULL)
    {
               printf("Cannot create the file");
               exit(1);
    }
    int n;
    printf("Enter the total number of students : ");
    scanf("%d",&n);
    for( i=0;i<n&&i<100;i++)
    {
            printf("Enter the details of Student %d\n",i+1);
            printf("Roll No : ");
            scanf("%d",&s[i].roll);
            fflush(stdin);
            printf("Name : ");
            gets(s[i].name);
            printf("Mobile Number : ");
            gets(s[i].mobile);
            printf("Home Town : ");
            gets(s[i].home);
    }
    for( i=0;i<n;i++)
    {
            fprintf(p,"%d\t",s[i].roll);
            fprintf(p,"%s\t",s[i].name);
            fprintf(p,"%s\t",s[i].mobile);
            fprintf(p,"%s\n",s[i].home);

    }
    fclose(p);
    p=fopen("student1.bio","r");

    for( i=0;i<n;i++)
    {
            fscanf(p,"%d\t",s[i].roll);
            fscanf(p,"%s\t",s[i].name);
            fscanf(p,"%s\t",s[i].mobile);
            fscanf(p,"%s\n",s[i].home);
            s[i].k=0;

    }
    for( i=0;i<n&&i<100;i++)
    {
            if(s[i].k==1)
            continue;
            printf("Home Town : %s\n",s[i].home);
            printf("%s\n",s[i].name);
            for( j=i+1;j<n;j++)
            {
                    if(stricmp(s[i].home,s[j].home)==0)
                    {
                                                       printf("%s\n",s[j].name);
                                                       s[j].k=1;
                    }
            }
            s[i].k=1;
    }



}

