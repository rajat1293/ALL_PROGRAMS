#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int vee[100002];
class vect
{
public:
	int *arr;
	vect(int s)
	{
		arr= new int[s+4];
	}	
	vect()
	{
	}
	void set(int s)
	{
		arr=new int[s+4];
	}
};
int main()
{
	int t;
	cin>>t;
 	while(t--)
{
	 bool area[100002]={0};
	 int countt=0;
	 int val=0;
	 bool flag=false;
	 int n,k,i,j;
	 cin>>n;
	 cin>>k;
	 vect A(k);
	 vect V[n+1];	
	 for(int i=1;i<=n;i++)	 	
	 V[i].set(k);
	 for(int i=1;i<=n;i++)	 	
{
		for(int j=1;j<=k;j++)
{
			cin>>V[i].arr[j];
}	
} 	
		for(int j=1;j<=k;j++)
{
			cin>>A.arr[j];
}	
	while(1)
{
		int rann=  rand()%n +1;
		if(area[rann]==true)
		continue;
		 val++;
		area[rann]=true;
		for( j=1;j<=k;j++)
		if(V[rann].arr[j]>A.arr[j])
		break;	
	    if(j==k+1)
{
	 	flag=true;
		for(j=1;j<=k;j++)
		{
			A.arr[j]=A.arr[j]-V[rann].arr[j];
		}	
		vee[countt++]=rann;
		// cout<<"1\n";
	 	//cout<<i<<endl;
		 //for(int j=1;j<=k;j++)
		//cout<<V[i].arr[j]<<" ";	
		//break;
}
	if(val==n)
	break;		 	
}
	if(!flag)
	cout<<"0\n";
	else 
	{
		cout<<countt<<endl;
		sort(vee,vee+countt);
		for(i=0;i<countt;i++)
		cout<<vee[i]<<" ";
		cout<<endl;
	}	
}
}
