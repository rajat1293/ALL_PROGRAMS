#include<stdio.h>
#include<math.h>
#include<conio.h>
//using namespace std;
int arr[1000001];
int main()
{
	int i,n,j,t,count=0;
//	scanf("%d",&t);
	int k=sqrt(1000001);
	for(i=3;i<=k;i+=2)
	{
		if(!arr[i])
		for(j=i*i;j<1000001;j=j+i*2)
		arr[j]=1;
 }
for(i=3;i<1000001;i+=2)
{
	if(!arr[i])
{count++;	
printf("%d %d\n",i,count);
getch();
}
}
printf("%d",count);
}

