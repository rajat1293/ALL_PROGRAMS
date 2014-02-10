#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int t;
     char *a[]={ "-----",".----","..---","...--", "....-", ".....","-....", "--...", "---..", "----."};
	scanf("%d",&t);
	while(t--)
{
		long long  n;
		scanf("%lld",&n);
		char str[20],*p,*s,*q;
		sprintf(str,"%lld",n);
		p=str;
		long long count=0;
		while((*p)!=0)
{
			printf("%s",a[(*p)-48]);
			s = a[(*p)-48];
			//cout<<s;
			while(*s!=0)
			{
			 if(*s=='.')
				count++;
				s++;
			}
			p++;	
}
		cout<<endl;
		printf("%lld\n",count);
		//cout<<count<<endl;
	}
}
