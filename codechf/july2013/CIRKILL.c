#include<stdio.h>
#include<math.h>
double fun(int a,int b)
{
int i,j=1;
double sum=1;
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
		int i,j,k,n,s=0;
		double radius,x1,x2,x,y,y1,y2,a[40],b[40];
		int flag1=0,flag2=0,l;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
	 scanf("%lf%lf",&a[i],&b[i]);
		 for(i=1;i<=n-2;i++)
		 {
		 	for(j=i+1;j<=n-1;j++)
		 	{
		 		for(k=j+1;k<=n;k++)
		 	   {
		 	   	flag1=flag2=0;
		 	   //	printf("%d %d %d\n",a[i],a[j],a[k]);
		 	   	//printf("%d %d %d\n",b[i],b[j],b[k]);
		 	   	if((a[i]==a[j])&&(a[j]==a[k])||((b[i]==b[j])&&(b[j]==b[k])))
		 	   	continue;
		 	   	else if((b[j]==b[k]||b[i]==b[j]));
		 	   	else if((a[i]-a[j])/(b[j]-b[i])==(a[j]-a[k])/(b[k]-b[j]))
		 	   	continue;
		 	   x1=	(a[i]+a[j])/2.0;
		 	   x2=(a[j]+a[k])/2.0;
		 	   y1=	(b[i]+b[j])/2.0;
		 	   y2=(b[j]+b[k])/2.0;
		 	   	if(b[i]==b[j])
		 	   {
					x=x1;
		 	   		flag1=1;
		 	   	}
					else
		 	   	y=y1+(a[i]-a[j])/(b[j]-b[i])*(x-x1);
		 	   	if(b[j]==b[k])
		 	  {
			     	x=x2;
					flag2=1;
				}
					else
		 	   	y=y2+(a[j]-a[k])/(b[k]-b[j])*(x-x2);
		 		
		 		if(flag1==0&&flag2==0)
		 		{
				 x=(y2-y1-(a[j]-a[k])/(b[k]-b[j])*x2+(a[i]-a[j])/(b[j]-b[i])*x1)/((a[i]-a[j])/(b[j]-b[i])-(a[j]-a[k])/(b[k]-b[j]));     
		 		y=y1+(a[i]-a[j])/(b[j]-b[i])*(x-x1);
		 	}
				 else if(flag1!=0&&flag2==0)
		 		{
		 			x=x1;
		 		   y=y2+(a[j]-a[k])/(b[k]-b[j])*(x1-x2);
		 	}
		 	else if(flag1==0&&flag2!=0)
		 	{
		 		x=x2;
		 		y=y1+(a[i]-a[j])/(b[j]-b[i])*(x2-x1);
		 	}
		 	
		 	 radius=sqrt((x-a[i])*(x-a[i])+(y-b[i])*(y-b[i]));  	
		 	
						for(l=1;l<=n;l++)
		 	   	{
		 	   		
		 	   		if(l!=i&&l!=j&&l!=k)
						 {
						if( (sqrt((x-a[l])*(x-a[l])+(y-b[l])*(y-b[l]))-0.000001)<=radius)
						s++; 
			 	       }
		 }
	}
}
}
printf("%lf\n",(double)s/(fun(n,3)*(n-3)));
}
return 0;
}
