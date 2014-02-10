//AUTHOR ---RAJAT GAMBHIR------
//DATE  14.8.13 time 0300hrs
#include<stdio.h>
#include<math.h>
	int S[21][20002];
int arr[21];
  int i,n,j,sum,flag,sum1;
//this program calculates if there exists a subset sum 
//ie is it feasible to calculate the subset sum .......
int main()
{
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		flag=0;
  scanf("%d",&n);
 scanf("%d",&sum1);
  for(i=1;i<=n;i++)
  {
  scanf("%d",&arr[i]);
sum+=arr[i];
}
for( i=0;i<=n;i++)
S[i][0]=1;
  for( i=1;i<=n;i++)
  {
  	for(j=1;j<=sum;j++)
  	{
  		if(j<arr[i])
  		S[i][j]=S[i-1][j];
  		else
  		{
		S[i][j]=(S[i-1][j]||S[i-1][j-arr[i]]);
 }
 if(j==sum1&&S[i][j])
{
 printf("Yes\n");
flag=1; //cout<<S[i][j]<<" ";     
break;
}
}
if(j!=(sum+1))
break;
//cout<<endl;
}
if(flag==0)
printf("No\n");
}
return 0;
}



