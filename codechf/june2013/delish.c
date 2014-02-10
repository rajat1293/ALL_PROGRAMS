//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
long long int llabs(long long int s){
	return (s>0)?s:-s;}
long long int indexx;
long long int minn1(long long int *sa,long long int ind)
{
	long long int as[10003];
	long long int max=0,min=0, sum=0,i,flag=0;
	
	for(i=ind;i>=0;i--)
	as[i]=-sa[i];
	for(i=ind;i>=0;i--)
	{
	sum=sum+as[i];
	if(sum<0)
	sum=0;
	if(max<sum)
	{max=sum;
	flag=1;}			
	}
if(flag)
	{
	return -max;
	}
	else
	{
		min=sa[ind];
		for(i=ind;i>=0;i--)
	{
			if(min>sa[i])
			min=sa[i];
        }
        return min;   	
}
}
long long int maxx1(long long int *sa,long long int n)
{
long long int max=0,sum=0,i,flag=0;	
	for(i=n-1;i>=1;i--)
    {
	sum=sum+sa[i];
	if(sum<0)
	sum=0;
	if(max<sum)
	{
	max=sum;
	indexx=i;
	flag=1;
    }
	}
	if(flag) return max;
	else
	{
    max=0;sum=0;
	for(i=n-1;i>=1;i--)
    {
	sum=sum+llabs(sa[i]);
	if(sum<0)
	sum=0;
	if(max<sum)
	{
	max=sum;
	indexx=i;
    }
	}
	return -max;
}

}
long long int minn(long long int *sa,long long int ind,long long int n)
{

	long long int as[10003];
long long int max=0,min=0, sum=0,i,flag=0;
	
	for(i=ind;i<n;i++)
	as[i]=-sa[i];
	for(i=ind;i<n;i++)
	{
	sum=sum+as[i];
	if(sum<0)
	sum=0;
	if(max<sum)
	{max=sum;
	flag=1;}			
	}
	if(flag)
	{
	return -max;
	}
	else
	{
		min=sa[ind];
		for(i=ind;i<n;i++)
		{
			if(min>sa[i])
			min=sa[i];
        }
        return min;   	
}
}
long long int maxx(long long int *sa,long long int n)
{
long long int max=0,sum=0,i,flag=0;	
	for(i=0;i<n-1;i++)
    {
	sum=sum+sa[i];
	if(sum<0)
	sum=0;
	if(max<sum)
	{
	max=sum;
    indexx=i;
     flag=1;
	}	
    }
    if(flag)    return max;
    else 
    {
    	sum=0;
		max=0;
    	for(i=0;i<n-1;i++)
    {
	sum=sum+llabs(sa[i]);
	if(sum<0)
	sum=0;
	if(max<sum)
	{
	max=sum;
    indexx=i;
     }	
    }
    return -max;
}    	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	long long int n,sa[10003],max,max1,min,min1,i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
    scanf("%lld",&sa[i]);
    max=  maxx(sa,n);
    max1=minn(sa,indexx+1,n);  
    min   =  maxx1(sa,n);
    min1  =minn1(sa,indexx-1);
    if(llabs(min-min1)>llabs(max-max1))
    printf("%lld\n",llabs(min-min1));
    else 
    printf("%lld\n",llabs(max-max1));
    }
    return 0;  
}

    

    

