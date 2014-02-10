#include<stdio.h>
#include<math.h>
main()
{int i,a,n,sum=0;
	printf("enter a number of n\n");
	scanf("%d",&n);
	for(i=1;i<10;i++)
	{
		a=n/pow(5,i);
		if(a>=1)
		{sum=sum+a;
		}else
		break;
		}
	printf("\nthe no of zeroes is %d",sum);
	
}
