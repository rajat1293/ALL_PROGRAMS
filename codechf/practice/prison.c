#include<stdio.h>
#include<string.h>
int main()
{
int i,j,k;
int t;
int col;
int mat[200][200];
scanf("%d",&t);
int c;
int count;
int dir;
char str[250];
int level;
for(i=0;i<t;i++)
{
scanf("%d",&c);
scanf("%s",str);
count=0;
dir=1;
level=0;
for(j=0;j<strlen(str);j++)
{
mat[level][count]=str[j];
if(dir==1)
{
if(count==c-1)
{
dir=0;
level++;
}
else
{
count++;
}
}
else
{
if(count==0)
{
dir=1;
level++;
}
else
{
count--;
}
}
}
printf("\n");
for(j=0;j<c;j++)
{
for(k=0;k<level;k++)
{
printf("%c",mat[k][j]);
}
}
}
return 0;
}

