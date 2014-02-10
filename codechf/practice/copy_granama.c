#include<stdio.h>
#include<string.h>
int main(){
int t;
scanf("%d",&t);
while(t--){
char a[1001],b[1001];
int c[27],d[27];
int i,j;
for(i=0;i<26;i++){
d[i]=0;
c[i]=0;
}
int l,m,x=0,p=0;
fflush(stdin);
scanf("%s%s",a,b);
l=strlen(a);
m=strlen(b);
for(i=0;i<l;i++)
c[a[i]-'a']++;
for(i=0;i<m;i++)
d[b[i]-'a']++;
for(i=0;i<26;i++)
{
	printf("%d %d\n",c[i],d[i]);
}
for(i=0;i<26;i++){
if(c[i]==d[i])
x++;
else if(c[i]==0||d[i]==0)
p=1;
else;
}
if(x==26||p==1)
printf("YES\n");
else printf("NO\n");
}
return 0;
}

