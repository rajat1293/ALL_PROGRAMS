#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<vector>
using namespace std; 
//-----------------
long long max(long long x,long long y)
{ return (y > x)? y : x; }
 
long long maxSubArraySum(vector<long long>& a,long long start, long long size)
{
  long long max_so_far = a[start], i;
   long long curr_max = a[start];
   for (i = start+1; i < size; i++)
   {
         curr_max = max(a[i], curr_max+a[i]);
        if(max_so_far<curr_max)	
      {
      	 max_so_far=curr_max;
	  } 
   }
   return max_so_far;
}
//-----------------


int main()
{
	int t;
	cin>>t;
//	freopen("rajat.txt","w",stdout);
	while(t--)
	{
		long long  n,k;
		 n=rand()%100+1;
		 k=rand()%n-2;
			cout<<n<<" "<<k<<endl;
		//cin>>n>>k;
		vector<long long> V(n+3);
		for(int i=0;i<n;i++)
		{
			V[i]=rand()%(2*1000000000)-1000000000;
			cout<<V[i]<<endl;
		}
		long long max= -100000000000LL,ans;
		for(long long i=n-k-1;i>0;i--)	
		{
			ans=maxSubArraySum(V,0,i);
			ans+=maxSubArraySum(V,i+k,n);
				if(ans>max)
				max=ans;				
		}
		cout<<endl<<endl;
		cout<<max<<endl;
	}
	
}

