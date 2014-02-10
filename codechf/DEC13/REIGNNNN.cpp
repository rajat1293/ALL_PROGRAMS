#include<iostream>
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
//------------------------
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long  n,k;
		cin>>n>>k;
		vector<long long> V(n+3);
		for(int i=0;i<n;i++)
			cin>>V[i];
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
	
	
	
	
	
