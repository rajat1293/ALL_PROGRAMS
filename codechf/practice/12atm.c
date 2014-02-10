#include<stdio.h>
int main()
{int k,n;
char m;
float i;
    scanf("%d",&n);
    scanf("%f",&i);
    scanf("%c",&m);
    fflush(stdin);
    if((float)(n+0.50)>i)
    {printf("%f",i);
        return 0;
		}
       if(n%5==0)
        {
        i=i-n-0.50;
        printf("%f",i);}
        else
        printf("%f",i);
    return 0;
}
