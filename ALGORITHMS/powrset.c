#include<stdio.h>
#include<string.h>
#include<math.h>
 bin(int i);
int a[20];
main(){
char s[20];
gets(s);
int i,n,j,k;
for(i=0;i<20;i++)
a[i]=0;
n=strlen(s);
printf("$\n"); /*phi*/
for(i=1;i<pow(2,n);i++)
{
bin(i);
for(k=0;k<n;k++)
{
if(a[k]==1)
printf("%c",s[k]);
}
printf("\n");
}}
 bin(int i)
 {
int j=0;
while(i>0){
a[j++]=i%2;
i=i/2;
}}
