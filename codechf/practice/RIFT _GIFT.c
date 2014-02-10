#include<stdio.h>
int  main()
{int   a[100][100];
  int f,b,i,j,s=1;
  	int lar,small;
  //char ll;
  int m,n,o,row,col;
//	printf("enter the no os rows and colms\n");
	scanf("%d%d",&row,&col);
	
//	printf("enter the eleents\n");
	for(i=0;i<row;i++)
	{
	for(j=0;j<col;j++)
	{
	scanf("%d",&a[i][j]);
}}	for(m=0;m<row;m++)
		{
		for(n=0;n<col;n++)	
	  {
	  lar=a[m][n];
	  for(o=0;o<row;o++)
	  {
	  	if(a[o][n]>lar)
	  	{
	  		lar=a[o][n];
	  	}
	  	
	  }
	  small=a[m][n];
	  for(o=0;o<col;o++)
	  {
	  	if(a[m][o]<small)
	  	small=a[m][o];
	  	
	  }	
	  if(small==lar)
	  {
	  	printf("%d",small);
	  	return 0;
	  	
	  }	
	  	}}	
	s=0;
	if(s==0)
{	printf("GUESS");
	return 0;
}
}


