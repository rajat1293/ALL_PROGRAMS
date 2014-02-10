#include<stdio.h>
//#include<conio.h>
int main(){
int t;
char m;
scanf("%d",&t);
scanf("%c",&m);
while(t--)
{
char a[315];
int c[27]={0};
int i;
fflush(stdin);
gets(a);
int l=strlen(a);
for(i=0;i<l;i++){
if(a[i]>=65&&a[i]<=90)
c[a[i]-'A']=1;
else if(a[i]>=97&&a[i]<=122)
c[a[i]-'a']=1;
}
for(i=0;i<26;i++){
if(c[i]==0){
printf("%c\n",i+'A');
break;
}
}
if(i==26)
printf("~\n");
}
//getch();
return 0;
}

