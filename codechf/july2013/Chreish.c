#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
	int n,m,k,path,blocks,tpath,i;
	double f;
	scanf("%d%d%d",&n,&m,&k);
	if((n==1&&m==2)||(n==2&&m==1)||(n==1&&m==1))
	{
	 printf("0\n");
	 continue;
	}
	if(n==1||m==1)
	{
	printf("%d\n",k);
	continue;
    }
    if(k%2==0)
    printf("%d\n",k/2);
    else
    printf("%d\n",(k+1)/2);
}
return 0;
}

