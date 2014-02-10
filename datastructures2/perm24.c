#include<stdio.h>
#include<conio.h>
#include<string.h>
int k=0;
void perm(char a[],int i,int n);
main()
{
int n;
char a[20];
printf("enter a string\n");
gets(a);
n=strlen(a);
printf("the perm are\n");
perm(a,0,n-1);
printf("\n%d",k);
getch();
}
void perm(char a[],int i,int n){
int j,temp;
if(i==n){
printf("%s\n",a);k++;}
else{
for(j=i;j<=n;j++)
{k++;
temp=a[j];
a[j]=a[i];
a[i]=temp;
perm(a,i+1,n);
temp=a[j];
a[j]=a[i];
a[i]=temp;
}
}}

