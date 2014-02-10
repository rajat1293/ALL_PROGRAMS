#include<stdio.h>
#include<string.h>
int main(){
int t,i,x;
scanf("%d",&t);
while(t--){
int count=0;
char a[2014];
scanf("%s",a);
int l=strlen(a);
i=l-1;
while(i>=0){
if(a[i]=='?'){
count++;
i--;
if(count==4){
a[i+1]='C';
a[i+2]='H';
a[i+3]='E';
a[i+4]='F';
count=0;
}}
else if(a[i]=='F'&&i>2)
{if((a[i-1]=='?'||a[i-1]=='E')&&(a[i-2]=='?'||a[i-2]=='H')
&&(a[i-3]=='?'||a[i-3]=='C')){
a[i-2]='H';
a[i-1]='E';
a[i-3]='C';
i=i-4;
count=0;
}
else i--;
count=0;}
else if(a[i]=='E'&&i>1)
{if((a[i-2]=='?'||a[i-2]=='C')&&(a[i-1]=='H'||a[i-1]=='?')&&(a[i+1]=='?')){
a[i-2]='C';
a[i-1]='H';
a[i+1]='F';
i=i-3;
count=0;
}else i--;
count=0;
}
else if(a[i]=='H'&&i>0)
{if((a[i-1]=='?'||a[i-1]=='C')&&(a[i+1]=='?')&&(a[i+2]=='?')){
a[i+2]='F';
a[i-1]='C';
a[i+1]='E';
i=i-2;
count=0;
}else i--;
count=0;
}
else if(a[i]=='C')
{
if((a[i+1]=='?')&&(a[i+2]=='?')&&(a[i+3]=='?')){
a[i+1]='H';
a[i+2]='E';
a[i+3]='F';
i=i-1;
}else i--;
count=0;}
else {i--;
count=0;
}
}
for(i=0;i<l;i++)
if(a[i]=='?')
a[i]='A';
a[l]='\0';
printf("%s\n",a);
}
return 0;
}

