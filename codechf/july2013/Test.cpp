//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
namespace IO
{
	const int SIZE =1<<19;
	char buff[SIZE],*p=buff+SIZE;
	char read_char()
	{
		if(p==buff+SIZE)
		{
			fread(buff,1,SIZE,stdin);
			p=buff;
		}
		return *(p++);
	}
	inline int read_int()
	{
		char  c ;
		while(!isdigit(c=read_char()));
		int r=c-'0';
		while(isdigit (c=read_char()))
		r=r*10+c-'0';
		return r;
	}
}
using namespace IO;
using namespace std;
int main()
{
	int t;
	printf("te");
	t=read_int();
	printf("t %d",t );
return 0;
}
	

