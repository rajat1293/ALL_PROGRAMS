#include<stdio.h>
#include<string.h>
int main()
{
	int t,f;
	scanf("%d",&t);
	while(t--)
	{
		char n[40];
		int k;
		scanf("%s",n);
	f=strlen(n);
	if(f==2)
	k=1;
	else
	k=((f)*(f-1)/2)-1;
	printf("%d\n",k);	
	}
return 0;	
}
