#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

char *getword()
{
     FILE *p;
     p=stdin;
     if(p==NULL)
     {
               printf("Error");;
               exit(1);
     }
     char *x=(char*)malloc(100*sizeof(char));
     fscanf(p,"%s",x);
     return x;
}
int main()
{

    char *x=getword();
    FILE *p;
    p=fopen("Rajat.txt","w");
    if(p==NULL)
     {
               printf("Error creating Rajat.txt");;
               exit(2);
     }
    fprintf(p,x);
    free(x);
    fclose(p);
    getch();
    return 0;
}
