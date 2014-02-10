#include<stdio.h>
int main()
{
int n;
char b;
	scanf("%d",&n);
	scanf("%c",&b);
	while(n--){
	char k[315];
    int a[27]={0},i;
//	fflush(stdin);
	gets(k);
	
	for(i=0;i<strlen(k);i++)
	{if(k[i]>=65 && k[i]<=90)
	a[k[i]-'A']=1;	  
else if(k[i]>=97 && k[i]<=122) 
a[k[i]-'a']=1;
}

for(i=0;i<=25;i++)
{
if(!a[i])
{
printf("%c\n",i+'A');
break;
}
}

if(i==26)
printf("~\n");
}
return 0;}
