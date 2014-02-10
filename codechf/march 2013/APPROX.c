#include<stdio.h>
int main()
{
	int t;
	char m;
	scanf("%d",&t);
	scanf("%c",&m);
	while(t--)
	{ 
	fflush(stdin);
	char s[1000008];
	 int a,i,l,sk;
	int k=2,kkk;
	 scanf("%d",&a);
	 sk=4687;
	 if(a==0)
	printf("%d\n",3);
	 
	 else{
	 
	 s[0]='3';
	 s[1]='.';
	 for(i=1;i<=a;i++)
	 {
	 	kkk=sk*10/33102;
	 	l=(char)(kkk);
	 	s[k++]=(l+48);
	 	sk=sk*10%33102;	
	 }
	 s[k]='\0';
		printf("%s\n",s);}
}
return 0;
}

