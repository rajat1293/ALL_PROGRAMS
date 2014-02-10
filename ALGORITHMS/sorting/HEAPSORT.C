#include<stdio.h>
#include<conio.h>
#include<math.h>
int hh=10;
void maxheapify(int *a,int i)
{
  int l;
  int r,k;
  l=2*i;
  r=2*i+1;
  int largest;
  if(a[i]<a[l] && l<=hh)
  largest=l;
  else largest=i;
  if(a[r]>a[largest] && r<=hh)
  largest=r;
  if(largest!=i)
  {
   k=a[i] ;
   a[i]=a[largest];
   a[largest]=k;
  maxheapify(a,largest);
  }
}
void build_max_heap(int *a)
{ int i;
     for(i=5;i>=1;i--)
maxheapify(a,i);
}
void heapsort(int *a)
{int c,i;
 build_max_heap(a);
for(i=10;i>=2;i--)
{c=a[1];
a[1]=a[i];
a[i]=c;
hh=hh-1;
maxheapify(a,1);
}}
int main()
{ int a[11],i;
printf("enter the elements\n");
for(i=1;i<=10;i++)
scanf("%d",(a+i));
heapsort(a);
printf("\nthe sorted array is\n");
for(i=1;i<=10;i++)
printf("%d\n",*(a+i));
getch();
}


