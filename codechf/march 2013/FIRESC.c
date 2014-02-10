#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MOD 1000000009
int qrsort(int a[],int p,int r)
{
int q ;
if(p<r)
  {

   q = patti(a,p,r);
   qrsort(a,p,q-1);
   qrsort(a,q+1,r);}
}
int patti(int a[],int p,int r)
{
     int x,i,j,t,k;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++)
        {
        if(a[j]<=x)
        {
            i=i+1;
            t=a[i];
            a[i]=a[j];
            a[j]=t;        
        }
    }
            k=a[i+1];
            a[i+1]=a[r];
            a[r]=k;
            return (i+1);

}
int main()
{
	int flag,t,j;
	scanf("%d",&t);
	while(t--)
	{
			
		int  arr[100003]={0};
		int arr2[100005][2],arr3[100007],N,gg,M,i,k,c,s,f=1;
		scanf("%d%d",&N,&M);
		for(i=0;i<M;i++)
		scanf("%d%d",&arr2[i][0],&arr2[i][1]);	
		for(i=0;i<M;i++)
		{
			if(arr[arr2[i][0]]||arr[arr2[i][1]])
			{
			if(arr[arr2[i][0]])
			arr[arr2[i][1]]=arr[arr2[i][0]];
			else
	        arr[arr2[i][0]]=arr[arr2[i][1]];
		    }
			else
			{arr[arr2[i][0]]=(i+1);
			arr[arr2[i][1]]=(i+1);			
		}//printf("%d %d %d %d\n",arr2[i][0],arr[arr2[i][0]],arr2[i][1],arr[arr2[i][1]]);
		}
		qrsort(arr,1,N);
		for(i=1;i<=N;i++)
		printf("%d ",arr[i]);
		k=1;
		c=1;
		flag=0;
		i=1;
		while(arr[i]==0)
		{
			arr3[f++]=1;
			i++;
		}	
		s=arr[i];
		for(i=i+1;i<=N;i++)
		{ 
		if(s==arr[i])
		{k++;
		flag=1;
		}
		else 
		{
		flag=0;
		arr3[f++]=k;
		}
		if(flag==0)
		{s=arr[i];
		k=1;
		}}
		arr3[f]=k;
		for(i=1;i<=f;i++)
	 {	 //printf("\n%d   ",arr3[i]);
	     c=c*arr3[i]%MOD;	
	}
		printf("%d %d\n",f,c);			
	}    
		   		return 0;
}
