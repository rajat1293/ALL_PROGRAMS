#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
inline int input()
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
	while(t--){
	int k=0,N;
	N=input();
	while(N>=2048)
	{N=N-2048;
	k++;}
	while(N>=1024){
	k++;
	N=N-1024;}
	 while(N>=512){
	  k++;
	  N=N-512;}
	 while(N>=256){N-=256;
	 k++;}
	 while(N>=128){N-=128;
	 k++;}
	 while(N>=64) {N-=64;
	 k++;}
	 while(N>=32) {N-=32;
	 k++;}
	 while(N>=16) {N-=16;
	 k++;}
	 while(N>=8) {N-=8;
	 k++;}
	 while(N>=4) {N-=4;
	 k++;}
	 while(N>=2) {N-=2;
	 k++;}
	 while(N>=1){N-=1;
	 k++;}
	 printf("%d\n",k);
	 }
	 return 0;
}
