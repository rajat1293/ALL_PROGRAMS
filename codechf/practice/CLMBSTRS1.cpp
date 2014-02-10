#include<iostream>
using namespace std;
#define MOD 1000000007;
inline int fib(int n)
{  
int i,s;
long k,prev,next;
if(n==1||n==2)
	{
	return 1;}	
	prev=1%MOD;
	next=1%MOD;
for(i=1;i<=n-2;i++)
{
	k=prev+next;
	k=k%MOD;
	prev=next;
	next=k;		
}
	return k;
}
	
inline int bin(long int a)
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
int main()
{ int M;
//char n;
	int t,f,N,G;
cin>>t;
while(t--)
	{
		cin>>N>>G;
	//	scanf("%c",&n);
	//	fflush(stdin);
		M=fib(N+1);
		f=bin(M);
		if(f==G)
		cout<<"CORRECT\n";
		else
		cout<<"INCORRECT\n";					
	}
	return 0;
		
}
