//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
using namespace std;
#include<vector>
struct node
{
	int c,p,t;
	int d;
	};
	int C[102][10003];
int main()
{

	int t;
	for(int i=0;i<=10003;i++)
	C[0][i]=0;
	for(int i=0;i<=102;i++)
	C[i][0]=0;
	cin>>t;
	while(t--)
{
	int n,W,tot=0;
	node ob[104];
	cin>>n>>W;
	for(int i=1;i<=n;i++)
{
	cin>>ob[i].c>>ob[i].p>>ob[i].t;
	tot+=ob[i].t;
	ob[i].d=ob[i].c*ob[i].p;
}
 	for(int i=1;i<=n;i++)
{
 		for(int j=1;j<=W&&j<=tot;j++)
{
 	if(j<ob[i].t)
 	C[i][j]=C[i-1][j];
 	else
 	C[i][j]=max(C[i-1][j],C[i-1][j-ob[i].t]+ob[i].d);		  
 //	cout<<C[i][j]<<" ";
}
//cout<<endl;
}
//	cout<<tot<<" "<<W<<endl;
	if(tot<=W)
	cout<<C[n][tot]<<endl;
	else
	cout<<C[n][W]<<endl;
}
}



