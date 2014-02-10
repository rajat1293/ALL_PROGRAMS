#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    FILE *fp,*ft;
char ch;
    fp=fopen("file3.exe","rb");
    if(!fp)
    {
        printf("cannot open file\n");
        exit(2);
    }
    ft=fopen("file9.exe","wb");
        if(ft==NULL)
        {
           printf("cannot open file\n");
           fclose(fp);
           exit(9);
        }
    while(1)
    {
        ch=fgetc(fp);
        if(ch==EOF)
        break;
        else
        fputc(ch,ft);
    }
    fclose(fp);
     fclose(ft);
}
