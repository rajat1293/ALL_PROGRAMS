#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
inline int input( )
{
int n=0;
int ch=getchar_unlocked();
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
return n;
}
int main()
{
	int t;
	t=input();
	while(t--)
	{
	    int N,C,i,k=0;
		N=input();
		C=input();
		for(i=0;i<N;i++){	
	k=k+input();}
if(C>=k)
printf("Yes\n");
else
printf("No\n");			
	}
	return 0;	
}
