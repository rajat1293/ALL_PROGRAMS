#include<iostream>
#include<vector>
using namespace std; 
//-----------------
long long max(long long x,long long y)
{ return (y > x)? y : x; }
 
long long maxSubArraySum(vector<long long>& a,long long start, long long size,long long &index)
{
  long long max_so_far = a[start], i;
   long long curr_max = a[start];
   index=0;
   for (i = start+1; i < size; i++)
   {
         curr_max = max(a[i], curr_max+a[i]);
        if(max_so_far<curr_max)	
      {
      	 max_so_far=curr_max;
		   index=i;
	  } 
   }
   return max_so_far;
}
//-----------------


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long  n,k;
		long long  index=0,ind;
		cin>>n>>k;
		vector<long long> V(n+3);
		for(int i=0;i<n;i++)
			cin>>V[i];
		long long ans=maxSubArraySum(V,0,n-(k+1),index);
		ans+=maxSubArraySum(V,index+1+k,n,ind);
		cout<<ans<<endl;		
	}
	
}
