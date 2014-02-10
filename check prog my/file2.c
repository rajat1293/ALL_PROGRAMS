#include<stdio.h>
#include<stdlib.h>
main()
{
FILE *fp;
char s[80];
fp=fopen("pr11.txt","r");
if(!fp)
{
    printf("cannot open file");
    exit(9);
}
while(fgets(s,79,fp)!=NULL)
    printf("%s",s);
    fclose(fp);

    }



