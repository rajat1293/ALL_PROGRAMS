#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fp;
    char s[80];
    fp=fopen("pr11.txt","w");
    if(!fp)
    {
        printf("cannot open file\n");
        exit(2);
    }
    printf("enter some line of text");
    while(strlen(gets(s))>0)
    {
        fputs(s,fp);
        fputc('\n',fp);
    }

}
