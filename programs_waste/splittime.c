#include<stdio.h>
#define d total_sec/60
void split_time(long int, int *, int *, int *);
main()
{
    long int total_sec;
    int hr,min,sec;
    printf("Enter the seconds\n");
    scanf("%d",&total_sec);
    sec=total_sec%60;
    min=d%60;
    hr=(d/60)%60;
    split_time(total_sec, &sec, &min, &hr);
}

void split_time(long int ts, int *s, int *m, int *h)
{
    printf("Total seconds: %d\n",ts);
    if(*h>23)
    *h-=24;



    printf("Time is %d:%d:%d",*h,*m,*s);
    return(0);
}
