#include<stdio.h>
#include<string.h>
int main()
{int t;
char m;
	scanf("%d",&t);
	scanf("%c",&m);
	while(t--)
	{
		fflush(stdin);
		char raj[210];
		int a[60]={0},i,s=0,k;
	scanf("%s",raj);
	for(i=0;i<strlen(raj);i++)
	{
		if(raj[i]>=65&&raj[i]<=90)
		a[raj[i]-65]++;
		else
		a[raj[i]-71]++;
	}
		for(i=0;i<52;i++)
	{
		if(a[i]==1)
		s++;
		else if(a[i]>1&&a[i]%2==0)
		{
			k=(a[i])/2;
			s=s+k;
		}
		else if(a[i]>1&&a[i]%2!=0)
		{k=(a[i]+1)/2;
		s=s+k;
		}
	}
		printf("%d\n",s);		
}
	return 0;	
}
