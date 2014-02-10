#include<stdio.h>
#include<string.h>
int main()
{
int t,cnt=0,i,n;
scanf("%d",&t);
while(t--)
{
	char a[106];
	cnt=0;
scanf("%s",a);
n=strlen(a);
for(i=0;i<n;i++)
{
if((a[i]=='A')||(a[i]=='D')||(a[i]=='O')||(a[i]=='P')||(a[i]=='Q')||(a[i]=='R'))
cnt++;
else if(a[i]=='B')
cnt=cnt+2;
}
printf("%d\n",cnt);
}
return 0;
}
