#include<stdio.h>
#include<string.h>
int mystrpos(char *, char, int);
main()
{
    int n,x;
    char str[20],a;
    printf("Enter the string:\n");
    scanf("%s",str);
    fflush(stdin);
    printf("Enter character:\n");
    scanf("%c",&a);
    n=strlen(str);
    x=mystrpos(str,a,n);
    printf("%d",x);
}
int mystrpos( char *addr, char q, int w)
{
    int i,k;
    for(i=0;i<w;i++)
    if(q==*(addr+i))
    {k=1;break;}
if(k==1)
return(i+1);
    else
    return(-1);
}
