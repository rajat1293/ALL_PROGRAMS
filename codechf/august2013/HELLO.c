#include<stdio.h>
typedef struct {
	int m[105],c[105];
	double r[105];
}plan;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double d,r,best[105];
		int i,index,u,n;
		plan p;
		scanf("%lf%d%d",&d,&u,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%lf%d",&p.m[i],&p.r[i],&p.c[i]);
		}
		for(i=1;i<=n;i++)
		best[i]=(p.r[i]*u*p.m[i]+p.c[i])/p.m[i];
		index=1;
		for(i=2;i<=n;i++)
		if(best[index]>best[i])
		index=i;
		if(best[index]<d*u)
		printf("%d\n",index);
		else
		printf("0\n");		
	}
	return 0;
}
