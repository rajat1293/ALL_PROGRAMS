#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
//--------------------
	long long seiv[1000005];
	bool arr[1000003];
	long long  val[1000004];
//------------------
	long long poww(long long  n,long long  m) 
{ 
  	if(m==0) return (1);
   	long long x=poww (n,m/2);
    if(m%2==0) return (x*x); 
	else return (((x*x))*n) ;
}
//-------------
void seive()
{
	arr[1]=true;
	long long  i,n,j,t;
	long long k=sqrt(1000001);
	for(i=3;i<=k;i+=2)
{
	if(!arr[i])
	for(j=i*i;j<1000001;j=j+i*2)
	arr[j]=true;
}
	for(i=4;i<1000001;i+=2)
{
	arr[i]=true;
}
}
//------------------------
int main()
{
	long long  prime[]={0,1,2,4,6,10,12,16,18,22,28,30,36,40};
	long long t;
	long long  index=1;
	seive();
	for(long long j=1;j<=1000001;j++)
	if(!arr[j])
	seiv[index++]=j;
	cin>>t;
	while(t--)
{
	memset(val,0,sizeof(val));
	long long i,ff;
	long long L,R,j,k;
	long long count=0;
	long long store;
	cin>>L>>R;	
	if(L==1)
	val[1] = -1;
	for(j=1;j<=78498;j++)
{
	for(k=1;k<=13;k++)	
{
	store=poww(seiv[j],prime[k]);
	
	if(store>=L&&store<=R)
{
			val[store-L+1]=1;			

}
}
}
	if(L%2==0)
{
	for(i=L;i<=R;i+=2)
{
		if(val[i-L+1]!=1)
		val[i-L+1]= -1;
}
}
	else
{
	for(i=L+1;i<=R;i+=2)
{
		if(val[i-L+1]!=1)
		val[i-L+1]= -1;
}	
}
	for(k=2;k<=78498;k++)
{
	j= seiv[k] - L%seiv[k];
	for(i=L+j;i<=R;i+=seiv[k])
{
	if(val[i-L+1]==1 || val[i-L+1]== -1)
	continue;
	val[i-L+1]= -1;
}	
}
	for(i=L;i<=R;i++)
	{
		if(val[i-L+1] == 1 || val[i-L+1]== 0)
		count++;
	}
	cout<<count<<endl;
}
}
