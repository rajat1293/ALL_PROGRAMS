#include<stdio.h>
#define MOD 1000000007	
int bin( long int a)
{
	int c=0,r,k=0;
	while(a)
	{
		r=a%2;
		if(r==1)
		k++;
		a=a/2;

}
return k;	
}
long int fib[1000001];
int main(){
int i;
fib[0]=1;
fib[1]=2;
for(i=2;i<999999;i++){
fib[i]=fib[i-1]+fib[i-2];
fib[i]%=MOD;
}
int M;
	int t,f,N,G;
scanf("%d",&t);
while(t--)
	{
		scanf("%d%d",&N,&G);
	   f=bin(fib[N-1]);
		if(f==G)
		printf("CORRECT\n");
		else
		printf("INCORRECT\n");					
	}
	return 0;
		
}
