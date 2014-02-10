//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
//#include<iostream>
#include<stdio.h>
#include<math.h>
//using namespace std;
int main()
{
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,a[150];
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		if(a[i]==1)
			m=i-1;
			for(i=n;a[i]!=1;i--)
			if(a[i]<a[i-1])
			break;
			if(a[i]==1)
			{
				printf("%d\n",m);
				continue;
			}
			m=i-1;
			printf("%d\n",m);
			
}
return 0;
}

