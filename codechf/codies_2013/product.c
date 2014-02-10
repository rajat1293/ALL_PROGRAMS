//AUTHOR ---@RAJAT GAMBHIR------
//COPYRIGHTS.....
#include<stdio.h>
#include<math.h>
int main()
{
	int i,t,count,j,n;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		for(i=1;i<n;i++)
		{
			for(j=i+1;j<=n;j++)
			if(((i*j)%(i+j))==0)
	        count++;
		}
		
		printf("%d\n",count);
	}
	return 0;
	
}

