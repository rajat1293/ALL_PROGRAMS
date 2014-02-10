#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{   char j[102],s[102];
	    int i,k=0,a[52]={0},b[52]={0};
		scanf("%s",j);
		scanf("%s",s);
		for(i=0;i<strlen(j);i++)
		{
			if(j[i]>=65&&j[i]<=90)
			a[j[i]-65]=1;
			else
				a[j[i]-71]=1;	
		}
		for(i=0;i<strlen(s);i++){
		if(s[i]>=65&&s[i]<=90)
			b[s[i]-65]++;
			else
				b[s[i]-71]++;
	}	
	for(i=0;i<52;i++)
	{
		if(a[i]==1&&b[i]>=1)
		k+=b[i];
}
	printf("%d\n",k);		
}
	return 0;
}
