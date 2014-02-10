#include<stdio.h>
#include<conio.h>
qrsort(int a[],int p,int r)
{int q;
    if(p<r)
    {
        q=parr(a,p,r);
        qrsort(a,p,q-1);
        qrsort(a,q+1,r);
    }
}
int parr(int a[],int p,int r)
{int pivot,k=p,j=r;
    pivot=a[p];
    while(1)
    {
        while(a[k]<=pivot) k++;
        while(a[j]>pivot)  j--;
       if(k<j) swap(a,k,j);

else{swap (a,j,p);
        return j;}
}}
swap(int a[],int k,int j)
{int o;
o=a[k];
a[k]=a[j];
a[j]=o;

}
int main()
{int a[8],r,i;
printf("enter the no of elements in the aaru");
scanf("%d",&r);
printf("the arry is\n");
for (i=0;i<r;i++)
{
    scanf("%d",&a[i]);
}
qrsort(a,0,r-1);
printf("the sortes arry is\t");
for (i=0;i<r;i++)
{
    printf("%d\t",a[i]);
}
getch();
}
