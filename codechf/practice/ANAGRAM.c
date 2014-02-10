#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	char j;
	scanf("%c",&j);
	fflush(stdin);
	while(t--)
	{
		char sa[50],as[50];
		int  s1[28]={0},s2[28]={0},i;
		scanf("%s%s",sa,as);
		for(i=0;i<strlen(sa);i++)
		s1[sa[i]-97]++;
			for(i=0;i<strlen(as);i++)
	     s2[as[i]-97]++;	
		for(i=0;i<26;i++)
		{
		if(s1[i]!=s2[i])
		break;
		}
		if(i==26)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;	
}
