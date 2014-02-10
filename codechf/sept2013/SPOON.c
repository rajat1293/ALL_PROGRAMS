//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
int main()
{
	long long i,C[66];
	int t;
	scanf("%d",&t);
	C[1]=1;
	for( i=2;i<=65;i++)
	{
		if(i%2!=0)
			C[i]=(2*(i+1)*C[i-1])/(i+2);
		else
			C[i]=2*C[i-1];
		}
		for(i=1;i<=65;i++)
		cout<<C[i]<<endl;
	while(t--)
	{
		long double n;
	//	scanf("%lld",&n);
}
}


