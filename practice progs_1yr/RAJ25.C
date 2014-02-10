#include<stdio.h>
#include<conio.h>
int xcmp(char*,char*);
 void main ()
{
int k;
char s[20];
char t[20];
clrscr();
printf ("enter the names");
scanf("%s%s",s,t);
k=xcmp(s,t);
printf("%d",k);
getch();
}
int xcmp(char*s,char*t)
{
int r=0;
while(*s!=0)
{
if(*s==*t)
{
s++;
t++;
continue;
}
else
{
r=*s-*t;
break;
}     }
return(r);
}




