#include<stdio.h>
void swap(int* a,int* b)
{ 
    int t;
    t=*a;
	*a=*b;
	*b=t;
}
int arr1[1000000];
int main()
{
		int t;
	scanf("%d",&t);
	while(t--)
	{
     int n,i,j,k,l=0,arr[1004];
     scanf("%d%d",&n,&k);
     for(i=1;i<=n;i++)
     	scanf("%d",&arr[i]);
	if(n==1)
     	{
		 printf("%d\n",0);
     	 continue;
        }
     	while(1)
     	{ 
     	j=0;
     		for(i=1;i<n;i++)
			 if(arr[i]>arr[i+1])
     		 {
     		 	l++;
			  swap(arr+i,arr+i+1);
                 arr1[l]=i;     	 
		      		  j++; 
     	    }
     		 if(j==0)
	    		 break;  
     }
   printf("%d\n",l);
   for(i=1;i<=l;i++)
   printf("%d ",arr1[i]);
       printf("\n");
	   }
   return 0;
}
