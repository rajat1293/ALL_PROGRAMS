#include<stdio.h>
int k=0;
#define MIN(a,b) a<b?a:b
#define MAX(a,b) a>b?a:b
int min(int a[],int n,int i=0)
{k++;
    if(i==n-1) return a[i];
    else
    {
        int nextmin=min(a,n,i+1);
        return MIN(a[i],nextmin);
    }
}

int max(int a[],int n,int i=0)
{k++;
    if(i==n-1) return a[i];
    else
    {
        int nextmax=max(a,n,i+1);
        return MAX(a[i],nextmax);
    }
}

int main()
{
    int a[]={100,2,3,4};
    printf("%d ",min(a,4));
    printf("%d",max(a,4));
    printf("\n%d",k);
}
