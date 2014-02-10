#include<stdio.h>
#include<stdlib.h>
void split_time(long int,int*,int*,int*);
void main()
{
long int total_sec;
printf("enter total time in seconds \n");
scanf("%ld",&total_sec);
int hr,min,sec;
split_time(total_sec,&hr,&min,&sec);
}
void split_time(long int t,int*h,int*m,int*s)
{
*h=t/3600;
*s=t%3600;
*m=*s/60;
*s=*s%60;
printf("%d:%d:%d",*h,*m,*s);
}
