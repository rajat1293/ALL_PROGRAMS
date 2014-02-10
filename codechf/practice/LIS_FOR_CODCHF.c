#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 int binary(int a[],int k,int low,int high)
{
                int mid,l;
                mid = (low+high)/2;
                if (low>high)
                return (low);
                else if(a[mid]==k)
                return mid;
                else if (a[mid]>k)
                {l=binary(a,k,low,mid-1);
                return l;}
                else {l=binary(a,k,mid+1,high);
                return l;}
}
                 int main()
            {
                 int n;
	             int p[100],i,l[100],k=0;
	             scanf("%d",&n);
	             for(i=0;i<n;i++)
	             scanf("%d",&p[i]);
	             for(i=n-1;i>=0;i--)
	{
		        if(i==(n-1))
			    l[k++]=p[i];
		        else if(p[i]>l[k-1])
		        l[k++]=p[i];
		        else if(p[i]==l[k-1]);
		        else if(p[i]<=l[0])
		        l[0]=p[i];
		        else
	{          	
	            int low=0,high=k-1,ll;
                ll= binary(l,p[i],low,high);
                l[ll]=p[i];
				}		
}
               for(i=0;i<k;i++)
               printf("%d\n",l[i]);
              printf("%d\n",k);
}
		
