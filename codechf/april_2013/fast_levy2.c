//AUTHOR ---@RAJAT GAMBHIR------
//COPYRIGHTS.....created on 6 /2 2013
//#include<iostream>
#include<stdio.h>
#include<math.h>
//using namespace std;


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
	int i,n,j,t,arr[10000]={0};
	int k=sqrt(10000);
	arr[1]=1;
	arr[0]=1;
	for(i=4;i<=10000;i+=2)
	arr[i]=1;
	for(i=3;i<=k;i+=2)
	{
	   	if(!arr[i])
		for(j=i*i;j<=10000;j=j+i*2)
		arr[j]=1;
 }
t=input();
while(t--)
{
	int count=0;
	n=input();
if(n<=5)
{
printf("%d\n",0);
continue;
}
for(i=n-2;i>=2;i-=2)
if((!arr[i])&&(!arr[(n-i)/2]))
count++;
printf("%d\n",count);
}
return 0;
}
