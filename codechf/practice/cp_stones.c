#include<stdio.h>
#include<string.h>
int main()
{
int test;
scanf("%d",&test);
char jewel[101];
char stone[101];
while(test>0)
{
scanf("%s",jewel);
scanf("%s",stone);
int a= strlen(jewel);
int b = strlen(stone);
int i=0;
int count=0;
while(i<b)
{
int j=0;
while(j<a)
{
if(stone[i] == jewel[j])
{
count++;
//printf("%d",count);
break;
}
j++;
}
i++;
}
printf("%d\n",count);
test--;
}
return 0;
} 
