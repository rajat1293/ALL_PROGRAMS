#include<stdio.h>
#include<stdlib.h>
int fract(int,int);
main()
{
    int n,d,m,a,b;
    printf("Enter the numerator n denominator as m/n\n");
    scanf("%d",&n);
    printf("/\n");
    scanf("%d",&d);
    if(d==0)
    {
        printf("Invalid Option...\nDenominator cant be zero");
        exit(2);
    }
    if(n>d)
    m=fract(n,d);
    else
    m=fract(d,n);
    a=n/m;
    b=d/m;
    printf("\nSimple fraction of %d/%d is %d/%d",n,d,a,b);}


    int fract(int num,int den)
    {
        int rem;
        rem=den%num;
    while(rem>=0){
    if(rem==0)
    return(num);
    den=num;
    num=rem;
    rem=den%num;}
}
