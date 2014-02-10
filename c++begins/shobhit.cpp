#include<stdio.h>
int list[]={0,2,3,4};
#define d 10
inline void print(int a[],int n)
{
     printf("{ ");
     for(int i=0;i<n;i++)
     {
      if(a[i]!=0){printf("%d ",a[i]);}
      
     }
     printf("}\n");
}
inline int sum(int [],int);
static int count;
void recurse(int a[],int i,int n)
{
      
     if(i==n)
     {
             count++;
             if(sum(a,n)==d)
             {
                            print(a,n);
             }
             return;
     }
     for(int j=0;j<sizeof(list)/sizeof(*list);j++)
     {
      a[i]=list[j];
      recurse(a,i+1,n);
     }     
}

int sum(int a[],int n)
{
 int s=0;
 for(int i=0;i<n;i++)
 {s+=a[i];}    
    return s;
    
}
int main()
{
  int a[10];
  recurse(a,0,7);
  printf("%d",count);
  getchar();
  return 0;
}
