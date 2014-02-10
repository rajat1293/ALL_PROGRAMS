#include<stdio.h>
#include<math.h>
int main()
{int l,i,n,k;
char m;
scanf("%d",&n);
scanf("%c",&m);
fflush(stdin);
while(n--)
 {
 scanf("%d",&k);
 l=log(k)/log(2);
 l=pow(2,l);
 printf("%d\n",l);
 }
return 0;
}

