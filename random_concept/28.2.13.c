#include<stdio.h>
int main( )
{
char *q;
q=(char*)malloc(10);
int j;
for (j=0; j<3; j++) scanf("%s" ,(q+j));
for (j=0; j<3; j++) printf("%c" ,*(q+j));
for (j=0; j<3; j++) printf("\n%s" ,(q+j));
}
