	/* This is a program to implement Shift-Reduce Parser*/


#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
 int i,j=0,k,len;
 char e,b[10],text[20],temp[10];
 clrscr();
 printf("\n shift reduce parsing");
 printf("\n enter input expression");
 scanf("%s",b);
 printf("input is %s\n",b);
 len=strlen(b);
 text[0]='$';
 j=1;
 printf("\n Stack\tOperation\tOutput");
 for(i=0;i<len;i++,j++)
 {
  text[j]=b[i];
  text[j+1]='\0';
  printf("\n %s\t shift%c\t\t",text,b[i]);
  for(k=i+1;k<len;k++);
   printf("%c",b[k]);
  if(text[j]=='a')
  {
   text[j]='E';
   printf("\n %s\t a is reduced to E",text);
  }
  else if(text[j]=='+'||text[j]=='*')
  printf("\n");
  else
  {
   printf("\n wrong input");
   getch();
  }
  if(strlen(text)>3)
  {
   temp[0]=text[j-2];
   temp[1]=text[j-1];
   temp[2]=text[j];
   temp[3]='\0';
   temp[j-2]='E';
   temp[j-1]='\0';
   printf("\n%S\t%s reduced to E \n",text,temp);
   j=j-2;
  }
 }
 printf("\n~~~input accepted~~`");
 getch();
}


