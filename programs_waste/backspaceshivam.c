#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    char str[30],m,c;
    int i=0,k=0,j=0,n=1,d;
    printf("Enter the string\n");
    gets(str);
    fflush(stdin);
    n=strlen(str);
    for(i=0;i<n;i++)
    switch(*(str+i))
    {case '\t':
            printf("\\t"); break;
                   case '\b':
            printf("\\b"); break;
            case '\\':
            printf("\\");
            printf("\\"); break;
            default:
            printf("%c",*(str+i));
    }}
