#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
int main()
{
    char src[FILENAME_MAX];
    char dest[FILENAME_MAX];
    printf("Source File= ");
    scanf("%s",src);
    printf("Destination File= ");
    scanf("%s",dest);
    FILE *s,*d;
    if((s=fopen(src,"r"))==NULL)
    { 
           perror("Error opening input file");
           getch();
           exit(1);
    }
    if((d=fopen(dest,"w"))==NULL)
    { 
           perror("Error creating output file");
           getch();
           exit(1);
    }    
    
    char ch;
    while(1)
    {
                   ch=fgetc(s);
                   if(ch==EOF) break;
                   if(ch=='@'||ch=='#'||ch=='$'||ch=='%'||ch=='&'||ch=='*')
                   {continue;}
                   else
                   {
                       if(isalpha(ch))
                       {
                                     if(islower(ch))
                                                    fputc(toupper(ch),d);
                                     else
                                                    fputc(tolower(ch),d);
                                                                            
                       }
                       else
                           fputc(ch,d);
                   }
                   
    }
    fclose(s);
    fclose(d);
}
