#include<iostream>
#include<vector>
using namespace std;
//---------------------------------------------------
long long max(long long x,long long y)
{ return (y > x)? y : x; }
//-----------------------------------------------------------
long long maxSubArraySumBB(vector<long long>& a,long long start, long long size,long long * maxx)
{
	maxx[size-1]=a[size-1];
  long long max_so_far = a[size-1], i;
   long long curr_max = a[size-1];
   for (i = size-2; i >= start; i--)
   {
         curr_max = max(a[i], curr_max+a[i]);
        if(max_so_far<curr_max)	
      {
      	 max_so_far=curr_max;
      	 maxx[i]=curr_max;
	  } 
	  else
	  maxx[i]=max_so_far;
   }
   return max_so_far;
}   
 //------------------------------------------------------------------------
long long maxSubArraySum(vector<long long>& a,long long start, long long size,long long * maxx)
{
	maxx[0]=a[start];
  long long max_so_far = a[start], i;
   long long curr_max = a[start];
   for (i = start+1; i < size; i++)
   {
         curr_max = max(a[i], curr_max+a[i]);
        if(max_so_far<curr_max)	
      {
      	 max_so_far=curr_max;
      	 maxx[i]=curr_max;
	  } 
	  else
	  maxx[i]=max_so_far;
   }
   return max_so_far;
}   
//--------------------------------------------------
int main()
{
	int n;
	vector<long long > arr(12);
	cin>>n;
	long long  maxx[34];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	maxSubArraySumBB(arr,0,n,maxx);
	cout<<endl;
	for(int i=0;i<n;i++)
	cout<<maxx[i]<<" ";
}
