#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
//#define gc getchar_unlocked
#define gc getchar
//-----------------
void scanint(long long int &x)
{
	register long long int c=gc();
	x=0;
	int long long  neg=0;
	for(;((c<48||c>57)&&c!='-');c=gc());
	if(c=='-')
	{
		neg=1;c=gc();
	}
	for(;c>47&&c<58;c=gc())
	{
		x=(x<<1)+(x<<3)+c-48;
	}
		if(neg)
		x=-x;
} 
//------
//-----------------
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
//-----------------


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long  n,k;
	//	cin>>n>>k;
		scanint(n);
		scanint(k);
		vector<long long> V(n+3);
		long long maxx[n+3];
		long long maxx2[n+3];
		for(int i=0;i<n;i++)
			scanint(V[i]);

			//cin>>V[i];
				//-------------preprocessing--------------------	
		maxSubArraySum(V,0,n,maxx);
		maxSubArraySumBB(V,0,n,maxx2);	
	//--------------------------------	
		long long max= -100000000000LL,ans;
		for(long long i=n-k-1;i>0;i--)	
		{
			ans=maxx[i-1];
			//cout<<ans<<" ";
			ans+=maxx2[i+k];
			//cout<<ans<<endl;
			//ans=maxSubArraySum(V,0,i);
			//ans+=maxSubArraySum(V,i+k,n);
				if(ans>max)
				max=ans;				
		}
		cout<<max<<endl;
	}	
}

