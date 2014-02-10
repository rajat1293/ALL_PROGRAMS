#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int N,C,i,a[103],k=0;
		scanf("%d%d",&N,&C);
		for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	for(i=0;i<N;i++)
	k=k+a[i];
if(C>=k)
printf("Yes\n");
else
printf("No\n");			
	}
	return 0;	
}
