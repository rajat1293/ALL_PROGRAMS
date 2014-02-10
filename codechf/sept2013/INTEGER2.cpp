//AUTHOR ---RAJAT GAMBHIR------
//DATE time 2200hrs date 6/9/13
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
	int n,b,j,X,mini,minii;
	scanf("%d",&n);
	int A[100004];
	int min=0,mun=0;
	for(int i=1;i<=n;i++)
	scanf("%d",&A[i]);
	scanf("%d",&X);
	j=0;
	//-----------
	mini=A[1];
	for(int i=2;i<=n;i++)
		if(A[i]<mini)
			mini=A[i];
minii= -mini;
//-----------
for(int i=1;i<=n;i++)
	{
		if(A[i]<0)
			min+=abs(A[i]);
	}	
while(1)
{
	j++;
	if(j<=(minii))
	{
		for(int i=1;i<=n;i++)
	{
		A[i]+=1;
	}
		mun=j*X;
		for(int i=1;i<=n;i++)
				if(A[i]<0)
					mun+=(-A[i]);
	}
	else
		break;
	if(mun<min)
		min=mun;
}
printf("%d\n",min);
}

