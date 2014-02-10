#include<stdio.h>
int main()
{
	int t,k,a[100],N,i=1,m,s,lar,count;
	scanf("%d",&t);
	while(t--)
	{   i=1;
	    count=0;
		scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&a[i]);
		i=1;
	    while(i<N)
	    {  
	       
	       lar=a[i+1];
	       m=i+1;
	       	for(k=i+2;s=k<=a[i]+i;k++)
	       	{
	       		if(a[k]>=lar)
	       		{
	       		lar=a[k];
				   m=k;	
	       	}
			   }
	       	i=m;
	       	count++;
	    }			
	    
	printf("%d\n",count);
}
	return 0;	
	
}
