#include<stdio.h>
#include<math.h>
//using namespace std;
int main()
{
	int i,n,j,t,arr[10001]={0};
//	scanf("%d",&t);
	int k=sqrt(10001);
	for(i=3;i<=k;i+=2)
	{
		if(!arr[i])
		for(j=i*i;j<10001;j=j+i*2)
		arr[j]=1;
 }
for(i=3;i<10001;i+=2)
{
	if(!arr[i])
	printf("%d ",i);
}
}

