#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
unsigned int tests=0;
unsigned successful=0;
void initialise(int a[])
{
     int k=0;
     for(int i=1;i<150;i++)
     {
             a[k++]=i;
             i+=2;
             a[k++]=i;
     }
}
int binarysearch(int a[],int low,int high,int key)
{
    tests++;
    if(low>high) return 0;
    int mid=(low+high)/2;
    if(a[mid]==key) return 1;
    else if(a[mid]<key) return binarysearch(a,mid+1,high,key);
    else return binarysearch(a,low,mid-1,key);
}
int main()
{
    srand(time(NULL));
    int a[99];
    initialise(a);
    for(int i=0;i<100;i++)
    {
            int key=rand()%151;
            if(binarysearch(a,0,99,key)) successful++;
    }
    printf("Total Searches                     = %d\n",100);
    printf("Total Successful Searches          = %d\n",successful);
    printf("Percentage of successful searches  = %d.00\n",successful);
    printf("Average no. of tests/search        = %.2f\n",(float)tests/100);    
    getch();
    return 0;
}
