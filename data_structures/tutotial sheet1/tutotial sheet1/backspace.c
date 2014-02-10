#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    char str[30];
    int i,n;
    printf("Enter the no. of  elements in the string\n");
    scanf("%d",&n);
    printf("Enter the string\n");
    for(i=0;i<n;i++)
    str[i]=getche();
    printf("\n");
    for(i=0;i<n;i++)
    switch(*(str+i))
    {case '\t':
            printf(" \\t "); break;
                   case '\b':
            printf(" \\b "); break;
            case '\\':
            printf(" \\\\");
            break;
            default:
            printf("%c",*(str+i));
    }}
