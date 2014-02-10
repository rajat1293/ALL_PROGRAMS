#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
     int n,i,k,arr[1004];
     scanf("%d%d",&n,&k);
     for(i=1;i<=n;i++)
     	scanf("%d",&arr[i]);
     	if(n==1)
     	{
		 printf("%d\n",0);
     	 continue;
        }
     	printf("%d\n",n-1);
     	for(i=1;i<=n-1;i++)
     	printf("%d ",i);
     	printf("\n");
}
return 0;
}


