#include<stdio.h>
long int fib[1000001];
int c[2][2];
static int **k;
int **cal(int **a,int **b)
{
	int i,j,k;
for(i=0;i<2;i++)
  {
	for(j=0;j<2;j++)
	{
	c[i][j]=0;
	for(k=0;k<2;k++)
	{
	c[i][j]=c[i][j]+a[i][k]* b[k][j];				
    }
   }
}
return c;
}
int **fun(int **a,int n)
{
	k=a;
if(n==1)
	return k;		
else
   {
	if(n%2==0)
	return fun(cal(a,a),n/2);
	return cal((fun(cal(a,a),n/2)),a);
	}	
}

int main()
{
	 
	 int arr[2][2]={0,1,1,1};
	 int **kk,i;
	 int F[2]={0,1};
     fib[0]=F[0];
	 fib[1]=F[1];
	 for(i=1;i<=;i++)
	 {
	kk=fun(arr,i);
	kk=cal(kk,F);
	fib[2]=k[1];		
    }
	printf("%d",fib[2]);	
}








