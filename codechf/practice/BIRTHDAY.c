#include<stdio.h>
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		int j,i,k=0,a[12]={0},min,smin;
		for(i=0;i<10;i++)
		scanf("%d",&a[i]);
		if(a[0]==0)
		{
			min=a[1];
			k=1;
	for(i=2;i<10;i++)
	{
		if(a[i]<min)
		{
		min=a[i];
		k=i;
		}			
	}
	if(min==0)
	printf("%d\n",k);
	else
	printf("%d%d\n",1,0);	
	}
	else{
	smin=a[1];
	k=1;
	for(i=2;i<10;i++)
	{
		if(a[i]<smin)
		{smin=a[i];
		k=i;}
	}
	if(smin>a[0])
	{
    printf("1");
    for(j=1;j<=(a[0]+1);j++)
    {
    printf("0");
    }
	}
	else {
	for(i=0;i<=smin;i++)
	printf("%d",k);}
	printf("\n");
}
	
	 }
	 return 0; 	
}
