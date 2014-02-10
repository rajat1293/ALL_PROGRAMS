#include<stdio.h>
#include<math.h>
void qrsort(int a[],int p,int r)
{
int q ;
if(p<r)
  {

   q = patti(a,p,r);
   qrsort(a,p,q-1);
   qrsort(a,q+1,r);}
}
int patti(int a[],int p,int r)
{
     int x,i,j,t,k;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++)
        {
        if(a[j]<=x)
        {
            i=i+1;
            t=a[i];
            a[i]=a[j];
            a[j]=t;        
        }
    }
            k=a[i+1];
            a[i+1]=a[r];
            a[r]=k;
            return (i+1);

}

int main()
{
	int t,j=0,arr1[102];
	scanf("%d",&t);
	while(t--)
	{
		int k,sum2=0,sum1=0,i,n,arr[105]={0};
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	    qrsort(arr,0,n-1);
	   if(k<=n-k)
	   {
	   	for(i=0;i<k;i++)
	   	sum1+=arr[i];
	   	for(i=k;i<n;i++)
	   	sum2+=arr[i];	
	   }
	   else 
	   {
	   	for(i=0;i<n-k;i++)
	   	sum1+=arr[i];
	   	for(i=n-k;i<n;i++)
	   	sum2+=arr[i];
	   }
	   printf("%d\n",abs(sum1-sum2));
}
return 0;
}
