#include<stdio.h>
#include<conio.h>
void main()
{
    FILE *ft;
    int i;
    char a,ch;
    ft =fopen("PR1.txt","w");
    if(ft==NULL)
    printf("the file cannot be opened");
    for(i=65;i<=92;i++)
    {
        printf("%c",i);
        fputc(i,ft);
        fprintf(ft,"%d",i);
        fputc('\n',ft);
    }
    printf("the file is created\n");
    fclose(ft);
    getch();
}

