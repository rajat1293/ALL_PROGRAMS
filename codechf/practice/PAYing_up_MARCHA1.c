#include<stdio.h>
#include<math.h>
long long  poww(long long x, int  n)
{if(n==1)
return x;
    if(n%2==0)
     return poww(x*x,n/2);
    return poww(x*x,n/2)*x;
}    
int main()
{
	int t,k;
	scanf("%d",&t);
	while(t--)
	{
		
		int i,n,m,d[20],sum,j;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
		scanf("%d",&d[i]);
		for(i=1;i<poww(2,n);i++)
		{
			sum=0;
			for(j=0;j<n;j++){
			if((k=(i&(1<<j)))!=0)
			sum=sum+d[j];
			}
			if(sum==m)
		{
			printf("Yes\n",sum);
			break;
		}
		}
		if(sum!=m)
		printf("No\n");
	}
	return 0;
}
