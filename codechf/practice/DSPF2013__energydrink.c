#include<stdio.h>
int main()
{
	int t,a[52],N,i=1,lar,count,k;
	char l;
	scanf("%d",&t);
	while(t--)
	{   i=1;
	    count=0;
		scanf("%d",&N);
		fflush(stdin);
		while((i++)<=N)
		scanf("%d",&a[i]);
		i=1;
	    while(i<N)
	    {  
	       if(a[i]==1)
		  {
		   count++;
		   i++;
          }
	    	else 
	    	{lar=a[i+1];
	    	for( k=i;k<(a[i]+i-1);k++)
	    	if(a[k+2]>lar)
	    	lar=a[k+2];
	    	i=lar+i;
	    	count++;
	        }
	        
	    }
	printf("%d\n",count);			
	}
	return 0;
	
}
