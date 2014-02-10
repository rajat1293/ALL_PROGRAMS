#include<stdio.h>
static int flag=0;
void func( int x,int step,char*c,int k)
{
	int j,i;
	if(x==step)
	{c[k]='\0';
	printf("%s\n",c);
	flag=1;
	return;}
	else 
	{
	return;}
else if(flag==0){
		*(c+k)='2';
	  func(x,2*step+1,c,k+1);
		if(step>1)
		{
		*(c+k)='1';
		func(x,2*step-1,c,k+1);	
	} }
	
}
int main()
{
	int t;
	 int x;
	char c[110];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&x);
		func(x,1,c,0);
		if(flag==0)
	printf("0\n");
	else 
	flag=0;
}
return 0;
}
