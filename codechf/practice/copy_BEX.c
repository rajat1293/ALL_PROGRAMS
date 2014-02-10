#include<stdio.h>
#include<string.h>
 
typedef struct{
int k;
char a[16];
}b;
b book[1000001],p;
int d[1000001];
int top=-1;
b pop();
int main(){
int n;
scanf("%d",&n);
int i,t;
int j=-1,m=0;
char s[16];
for(i=0;i<n;i++){
//fflush(stdin);
scanf("%d",&t);
if(t==-1&&top!=-1)
{
p.k=book[top].k;
strcpy(p.a,book[top--].a);
t=p.k;
printf("%d %s\n",m-d[j],p.a);
m=d[j]-1;
j--;
}
else if(t==-1&&top==-1)
;
else {
if(t!=0)
{m++;
scanf("%s",s);
if(top==-1){
book[++top].k=t;
strcpy(book[top].a,s);
d[++j]=m;
}
else{
if(book[top].k>=t){
book[++top].k=t;
strcpy(book[top].a,s);
d[++j]=m;
}
}}
else
scanf("%s",s);
}
}return 0;
}
