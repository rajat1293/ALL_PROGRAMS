//AUTHOR ---RAJAT GAMBHIR------
//DATE  14.8.13 time 0300hrs
#include<stdio.h>
#include<math.h>
//this program calculates if there exists a subset sum 
//ie is it feasible to calculate the subset sum .......
int S[21][20002];
int arr[21];
int main()
{
  int i,n,j,sum=0,sum1;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
  scanf("%d",&arr[i]);
  sum+=arr[i];
}
scanf("%d",&sum1);
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
		S[i][j]=max(S[i-1][j],S[i-1][j-arr[i]]);
 }
 //cout<<S[i][j]<<" ";     

}
//cout<<endl;
}
if(S[n][sum1])
printf("Yes\n");
else
printf("No\n");
return 0;
}



