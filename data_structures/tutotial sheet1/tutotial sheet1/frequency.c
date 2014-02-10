#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void mystrpos(char*);
void main()
{
char name[25];
printf("enter the string\n");
scanf("%s",name);
mystrpos(name);
}
void mystrpos(char*s)
{
int len,i,k,p,j;
len=strlen(s);
for(i=0;i<len;i++)
{
    for(p=0;p<i;p++)
{
    if(s[i]==s[p])
    goto dd;}
    k=1;
for(j=i+1;j<len;j++)
{
if(s[i]==s[j])
k=k+1;
}
printf("the frequency of %c is %d\n",s[i],k);
dd:
printf("");
}
}

