#include<stdio.h>
#include<conio.h>
void xcat(char*,char*);
 main()
{
char s[6]="rajat";
char t[8]="gambhir";
xcat(s,t);
printf("sourse after cat %s",s);
}
void xcat(char*s,char*t)
{
while(*s!='\0')
s++;
while(*t!='\0')
{
*s=*t;
s++;
t++;
}
*s='\0';
}
