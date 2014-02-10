#include<stdio.h>
int main()
{
	int t=10,a[10],i;
	while(t--)
	{
		int b[42]={0};
		int c=0;
		for(i=0;i<10;i++)
		scanf("%d",&a[i]);
		for(i=0;i<10;i++)
{
	if(	b[(a[i]%42)]!=1)
	c++;
	b[(a[i]%42)]=1;}	
	printf("%d\n",c);
    }
	return 0;
	
}
