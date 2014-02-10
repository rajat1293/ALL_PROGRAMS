#include<stdio.h>
int qrsort(int a[],int p,int r)
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
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int c=0,n,i,j,pi[32],a[32];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		scanf("%d",&pi[i]);
		for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	    qrsort(pi,0,n-1);
	    qrsort(a,0,n-1);
	    j=0;
	    for(i=0;i<n;i++)
	    {
	    	if(pi[j]<=a[i])
	    	{j++;
	    	c++;
	    	}	
	    }
	   printf("%d\n",c);		
	}
	return 0;	
}
