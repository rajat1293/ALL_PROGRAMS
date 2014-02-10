//AUTHOR ---@RAJAT GAMBHIR------
//COPYRIGHTS.....
//#include<iostream>
#include<stdio.h>
#include<math.h>
//using namespace std; 
long long int r;
void fun(int p,int q,int n,int m,int a,int b)
{
	
	if(a==n&&b==m)
	{
	r++;
	return ;}
	else 
	{

		if((a)!=p&&(b+1)!=q&&(a)<=n&&(a)>=1&&(b+1)>=1&&(b+1)<=m)
		 fun(p,q,n,m,a,b+1);
		 if((a+1)!=p&&(b)!=q&&(a+1)<=n&&(a+1)>=1&&(b)>=1&&(b)<=m)
	     fun(p,q,n,m,a+1,b);
	     if((a)!=p&&(b-1)!=q&&(a)<=n&&(a)>=1&&(b-1)>=1&&(b-1)<=m)
		fun(p,q,n,m,a,b-1);
		if((a-1)!=p&&(b)!=q&&(a-1)<=n&&(a-1)>=1&&(b)>=1&&(b)<=m)
		 fun(p,q,n,m,a-1,b);
		 
			
	}
		
}
int main()
{
	int t,n,m,p,q;
	scanf("%d",&t);
	while(t--)
	{ 
	   r=0;
		scanf("%d%d",&n,&m);
		scanf("%d%d",&p,&q);
		if(p==n&&q==m)
		{
		printf("0\n");
		continue;}
		else
		{
			fun(p,q,n,m,1,1);
			printf("%lld\n",r);
		}	
	}
	return 0;	
}

