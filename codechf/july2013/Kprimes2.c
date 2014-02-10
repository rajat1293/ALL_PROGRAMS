#include<stdio.h>
#include<math.h>
int main()
{int t;
int flag=0,i,n,a,m=0,b,k,arr[100003]={0},j;
	scanf("%d",&t);
	for(i=2;i<=100000;i++)
	{ 
	flag=0;
	n=i;
	while(n%2==0)
	{
		n=n/2;
		if(!flag)
		arr[i]++;
		flag=1;		
	}
	
	for(j=3;j<=sqrt(n);j+=2)
	{
		flag=0;
		while(n%j==0)
		{
			n=n/j;
			if(!flag)
		    arr[i]++;
		    flag=1;
		}
	}
		if(n>2)
		arr[i]++;
		}
	while(t--)
	{
		m=0;
		scanf("%d%d%d",&a,&b,&k);
	 for(i=a;i<=b;i++)
	  if(arr[i]==k)
	   m++;
	   printf("%d\n",m);
}
return 0;
}
