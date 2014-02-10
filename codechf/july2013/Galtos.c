#include<stdio.h>
#include<stdlib.h> 
#include<limits.h>
  inline int input( )
    {
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
    }
  struct node{
	int id;
	struct node* link;
};
struct node *temp;
int cost[1000007],min[1000003],arr1[1000003]={0};
int main()
{
	struct node* arr[100003];
	int mini,index;
	int sum=0,n,m,i,j=0,k=0,a,b;
	//scanf("%d%d",&n,&m);
	n=input();
	m=input();
	for(i=1;i<=n;i++)
	arr[i]=NULL;	
	for(i=1;i<=m;i++)
	{
		//scanf("%d%d",&a,&b);
		a=input();
	    b=input();
		struct node * temp1,*temp2;
		if(a==b)
		continue;
		if(arr1[a]==0&& arr1[b]==0)
		{
		temp1= (struct node*)malloc(sizeof(struct node));
		temp2= (struct node*)malloc(sizeof(struct node));
		temp1->id=a;
		temp2->id=b;
		temp1->link=temp2;
		temp2->link=arr[++j];
		arr[j]=temp1;
		arr1[a]=j;
		arr1[b]=j;
		}
	else if(arr1[a]!=0&&arr1[b]==0)
	  {
	  	temp2= (struct node*)malloc(sizeof(struct node));
		temp2->id=b;
		temp2->link=arr[arr1[a]];
       arr[arr1[a]]=temp2;	
       arr1[b]=arr1[a];
	}
	else if(arr1[a]==0&&arr1[b]!=0)
	  {
	  	temp1= (struct node*)malloc(sizeof(struct node));
		temp1->id=a;
		temp1->link=arr[arr1[b]];
		arr[arr1[b]]=temp1;
		arr1[a]=arr1[b];	
	}
	else if(arr1[a]!=0&&arr1[b]!=0&&arr1[a]!=arr1[b])
	{
		temp=arr[arr1[a]];
		while(temp->link!=NULL)
		temp=temp->link;
		temp->link=arr[arr1[b]];
		temp=temp->link;
		arr[arr1[b]]=NULL;
		while(temp!=NULL)
		{
		arr1[temp->id]=arr1[a];
	    temp=temp->link;
	}
}
}
		for(i=1;i<=n;i++)
		cost[i]=input();
		//scanf("%d",&cost[i]);
		if(n==1)
		{
		printf("0\n");
		return 0;
	    }
		if(m==0)
		{
			mini=cost[1];
			index=1;
			for(i=2;i<=n;i++)
			{
				if(cost[i]<mini)
				{
				index=i;
				mini=cost[i];
			}
		}
		for(i=1;i<=n;i++)
		{
			if(cost[i]<0)
			{
			printf("-1\n");
			return 0;
		}
			if(i!=index)
		sum=sum+mini+cost[i];
		}
		printf("%d\n",sum);
	return 0;
    }
    for(i=1;i<=n;i++)
    if(arr1[i]==0)
    {
    	temp= (struct node*)malloc(sizeof(struct node));
		temp->id=i;
		temp->link=NULL;
		arr[++j]=temp;
        arr1[i]=j;
    }
	 
	for(i=1;i<=j;i++)
	{
	if(arr[i]!=NULL)
  {
	temp=arr[i];
	min[++k]=INT_MAX;
	while(temp!=NULL)
	{
	if(cost[temp->id]<=min[k]&&cost[temp->id]>=0)
	min[k]=cost[temp->id];
	temp=temp->link;
   }
}
   }
   if(k==1)
    {
	  printf("0\n");
	  return 0;
    }
   mini=INT_MAX;
   for(i=1;i<=k;i++)
   {
   	if(min[i]<mini&&min[i]!=INT_MAX)
   	{  
   	   index=i;
	   mini=min[i];
    }
    else if(min[i]==INT_MAX)
	{
	printf("-1\n");
	return 0;
    }
    }
    for(i=1;i<=k;i++)
    if(i!=index)
      sum=sum+mini+min[i];
    	printf("%d\n",sum);
    	return 0;
}

