#include<stdio.h>
	  long  poww(long  x, int  n)
	 {
		 if(n==1)
	    return x;
	     if(n%2==0)
	      return poww(x*x,n/2);
	     return poww(x*x,n/2)*x;
	 }  
	int main()
	{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		long sum=0,total=0;
		double pp=0,sumFinal=0;
		int n;
		scanf("%d",&n);
	   int *a=new int[n];
		double* p=new double[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		    total+=a[i];
		}
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&p[i]);
		      p[i]/=100.0;
		  }
	for(int i=1;i<poww(2,n);i++)
	{
		pp=1;
		sum=0;
		for(int j=0;j<n;j++){
			
			if((k=(i&(1<<j)))!=0)
			{
				pp=pp*p[j];
				sum+=a[j];
			}
			else
			{
				pp=pp*(1-p[j]);
			}	
	}
if(sum>=total/2)
{
	sumFinal+=pp;

}
	}
printf("%lf\n",sumFinal);	
 }
}

