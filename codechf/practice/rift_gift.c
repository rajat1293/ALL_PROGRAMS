#include<stdio.h>
int	sa(int a[][100],int row,int col)
	{
		int i,j,k;
		int lar,small;
		for(i=0;i<row;i++)
		{
		for(j=0;j<col;j++)	
	  {
	  lar=a[i][j];
	  for(k=0;k<row;k++)
	  {
	  	if(a[k][j]>lar)
	  	{
	  		lar=a[k][j];
	  	}
	  	
	  }
	  small=a[i][j];
	  for(k=0;k<col;k++)
	  {
	  	if(a[i][k]<small)
	  	small=a[i][k];
	  	
	  }	
	  if(small==lar)
	  {
	  	printf("%d",small);
	  	return 1;
	  }	
	  	}
	}
	return 0;
}
int main()
{int   arr[100][100];
  int a,b,i,j,s;
  char n;
//	printf("enter the no os rows and colms\n");
	scanf("%d%d",&a,&b);
	scanf("%c",&n);
	fflush(stdin);
//	printf("enter the eleents\n");
	for(i=0;i<a;i++)
	{
	for(j=0;j<b;j++)
	{scanf("%d",&arr[i][j]);
	}}
	s=sa(arr,a,b);	
	if(s==0)
	printf("GUESS");
return 0;
	}



