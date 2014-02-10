#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[1001],k[1001];
		int c,i,ji=0;
		c=0;
		int b[27]={0},a[27]={0};
		scanf("%s",s);
		scanf("%s",k);
		for(i=0;i<strlen(s);i++)
	    a[s[i]-97]++;
		for(i=0;i<strlen(k);i++)
		b[k[i]-97]++;
		for(i=0;i<26;i++)
		{
		if(a[i]==b[i])
		c++;
		else if(a[i]==0||b[i]==0)
		ji=1;
		}
		if(c==26||ji==1)
		printf("YES\n");
		else
		printf("NO\n");		
	}
	return 0;	
}
