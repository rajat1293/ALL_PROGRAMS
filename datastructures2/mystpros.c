#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mystrpos(char*,char);
void main()
{
char name[23],ch;
int k;
printf("enter a string\n");
scanf("%s",name);
fflush(stdin);
printf("enter a character to be searched\n");
scanf("%c",&ch);
k=mystrpos(name,ch);
if(k>0)
printf("the first occirence of char is %d\n",k);
else
printf("no such chsrscter exxitss");
}
int mystrpos(char *n,char h)
{
int len,i,l=1;
len=strlen(n);
for(i=0;i<len;i++)
{

if((h<=90&&h>=65)||(h<=122&&h>=97))
{
    if(n[i]==h)
return(l);
}
l++;
}
return(-1);
}


