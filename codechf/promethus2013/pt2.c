//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<stdio.h>
#include<math.h>
int a[106],n,j,s,indexx,min,i,m=0;
int mini()
{int k;
min=a[j];
for(k=j+1;k<=n;k++)
if(min>a[k])
{
min=a[k];
indexx=k;
m=indexx;
}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		i=1;
		m=0;
		min=1;
		indexx=1;
		j=1;
		mini();
	    while(1)
	    {
	    		for(j=indexx;j<n;j++)
	    		if(a[j]>a[j+1])
	    		mini();
	    		break;
	    	}
	    	if(a[m]==1||(a[1]==1&&m!=0))
	    	{
		
	    		printf("%d\n",m-1);
	    }
	     else
	    	printf("%d\n",m);}
	return 0;
}
