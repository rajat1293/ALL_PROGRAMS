#include<stdio.h>
int main()
{
int t;
char m;
scanf("%d",&t);
scanf("%c",&m);
while(t--)
{
	fflush(stdin);
int a,i,s;
int k;
scanf("%d",&a);
s=4687;
if(a==0)
printf("%d\n",3);
else{
printf("%d.",3);
for(i=1;i<=a;i++)
{
k=s*10/33102;
printf("%d",k);
s=s*10%33102;
}
printf("\n");
}}
return 0;
}
