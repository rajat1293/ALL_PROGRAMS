//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int i,j,k,l,m,t,min;
	int a[10][10];
	scanf("%d%d",&m,&t);
	for(i=0;i<m;i++)
	for(j=0;j<m;j++)
	scanf("%d",&a[i][j]);
	for(i=0;i<(m-t+1);i++)
	{
	for(j=0;j<m-t+1;j++)
	{
		min=a[i][j];
		for(k=i;k<i+t;k++)
		{  
			for(l=j;l<j+t;l++)
			{
				if(a[k][l]<min)
				min=a[k][l];	
			}
		}
		printf("%d ",min);	
	}
	printf("\n");
   }
return 0;
}

