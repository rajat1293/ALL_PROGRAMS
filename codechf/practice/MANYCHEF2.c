#include<stdio.h>
#include<string.h>
int main()
{int t;
  char m;
  char a[2014];
	scanf("%d",&t);
	scanf("%d",&m);
	fflush(stdin);
	while(t--)
	 { 
	  int i;
	 int k;			
	    gets(a);
	    k=strlen(a);
	    for(i=(k-1);i>=0;i--)
	    {
	    	if((a[i]=='?'||a[i]=='F')&&(a[i-1]=='?'||a[i-1]=='E')&&(a[i-2]=='?'||a[i-2]=='H')&&(a[i-3]=='?'||a[i-3]=='C'))
	    	{
			   a[i]='F';
	    	   a[i-1]='E';
	    	   a[i-2]='H';
	    	   a[i-3]='C';
	        }
	    	else 
	    	{
	    	if(a[i]=='?')a[i]='A';
			if((a[i-1]=='?'||a[i-1]=='F')&&(a[i-2]=='?'||a[i-2]=='E'));
			else{
			if(a[i-1]=='?')a[i-1]='A';
		    }
		    if((a[i-2]=='?'||a[i-2]=='E')&&(a[i-2]=='?'||a[i-2]=='H'));
			else{
			if(a[i-2]=='?')a[i-2]='A';
		    }
		}
		    
	}
	   puts(a);
	}
	return 0;
}
