//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
#include<math.h>
int main()
{
	int m,i,k;
	int a[100003];
	scanf("%d",&m);
	for(i=0;i<m;i++)
	scanf("%d",&a[i]);
	printf("3\n");
	printf("%d %d ",a[0],a[1]);
	int d=abs(a[0]-a[1]);
	for(i=2;i<m;i++)
	{
		if(!(((abs(a[i]-a[1]))==d)||((abs(a[i]-a[0]))==d)))
		{
			printf("%d",a[i]);
			break;
		}
	}
	return 0;
}
		
		

