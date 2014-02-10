#include<stdio.h>
using namespace std;
inline int fun(int a,int b)
{
int i,j=1;
int  sum=1;
	for(i=a;j<=b;j++,i--)
	{
		sum=sum*i/j;
	}
	return sum;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double num=0,x;
	int i,t1,t2,t3,t4;
	scanf("%d%d%d%d",&t1,&t2,&t3,&t4);		
		for(i=t1;i>0;i--)
		{
			x=t4+i-t1;
			while(x>=0)
			{
			if((t4-x+i-t1)<=t3&&x<=t2)
		    num=num+(i/(i+t2-x))*fun(t2,x)*fun(t3,(t4+i-t1-x))*fun(t1,i);
             x=x-1;                          	
}
}
printf("%lf\n",num/fun((t1+t2+t3),t4));
}
return 0;
}
