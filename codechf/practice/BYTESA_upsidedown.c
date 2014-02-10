#include<stdio.h>
#include<string.h>
int main()
{   int i,t,flag=1;
    char arr[100];
    char ar[100];
	scanf("%d",&t);
	while(t--)
	{
		flag=1;
		scanf("%s",arr);
		int p=strlen(arr);
		ar[p--]='\0';
		for(i=0;i<p;i++)
		{
			if(arr[i]=='1')
			ar[p--]='1';
			else if(arr[i]=='6')
			arr[p--]='9';
			else if(arr[i]=='8')
			arr[p--]='8';
			else if(arr[i]=='9')
			arr[p--]='6';
			else
			{flag=0;
			break;
			}	
		}
		if(flag)
		{printf("YES\n%sar\n",ar);
		}
		else
		printf("NO\n");
		
	}
	
	return 0;
	
}
