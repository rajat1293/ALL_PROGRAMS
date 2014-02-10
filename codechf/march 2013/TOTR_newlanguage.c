#include<stdio.h>
#include<string.h>
int main()
{
	        int t,i;
	        scanf("%d",&t);
	        char in[60];
		    scanf("%s",in);
		    for(i=0;i<26;i++)
		    in[26+i]=in[i]-32;
	        while(t--)
	{
       		char raj[108],sen[108];
	    	scanf("%s",sen);
		    for(i=0;i<strlen(sen);i++)
		{
			if(sen[i]>=97&&sen[i]<=122)
			raj[i]=in[sen[i]-97];
			else if(sen[i]>=65&&sen[i]<=90)
			raj[i]=in[sen[i]-39];
			else if(sen[i]=='_')
			raj[i]=' ';
			else
			raj[i]=sen[i];
		}
      		raj[i]='\0';
	    	printf("%s\n",raj);
	}
	    	return 0;	
}

