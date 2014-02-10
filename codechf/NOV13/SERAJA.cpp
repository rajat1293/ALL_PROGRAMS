#include<iostream>
#include<vector>
using namespace std;
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
	for( i=1;i<=n;i++)
{
		for( j=1;j<=k;j++)
		if(V[i].arr[j]>A.arr[j])
		break;	
	    if(j==k+1)
{
	 	flag=true;
		 cout<<"1\n";
	 	cout<<i<<endl;
		 //for(int j=1;j<=k;j++)
		//cout<<V[i].arr[j]<<" ";	
		break;
}
		 	
}
	if(!flag)
	cout<<"0\n";	
}
}
