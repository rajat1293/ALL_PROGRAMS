#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int flag=0,i,s,a,m=0,b,k,arr[100003]={0},j=2;
		scanf("%d%d%d",&a,&b,&k);
		for(i=a;i<=b;i++)
		{
		flag=0;  
		j=2;
		   s=i;
			while(s!=1)
		   {
		    if(s%j==0)
		    {
		   s=s/j;	   	
		   	if(!flag)
		    arr[i]++;
			flag=1;
		   }
	       else
		    {
		    j++;
		    flag=0;
		    }
	       }
	if(arr[i]==k)
		m++; 
		}
		printf("%d\n",m);
	}
   return 0;
}
		   
		   
