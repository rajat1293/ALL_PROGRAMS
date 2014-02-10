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
//-----------------


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long ans;
		int index1,index2;
		long long min;
		bool flag=false;
		long long  sum=0,n,k;
		cin>>n>>k;
		if(k==0)
		 {
		 	k=1;
		 	flag=true;
		 }
		vector<long long> V(n+3);
		for(int i=0;i<n;i++)
			cin>>V[i];
			for(int i=1;i<=k;i++)
				sum += V[i];
				min = sum;
				index1=1;
				index2=k;
		for(int i=1+k;i<=n-2;i++)
		{
			sum =sum-V[i-k]+V[i];
			if(sum<min)
			{
				min=sum;
			    index2 = i;
			    index1 = i-k+1;
			}
		}
		if(min>=0&&flag==true)
			{
				ans=maxSubArraySum(V,0,n);
				cout<<ans<<endl;
				continue;
			}
		 ans=maxSubArraySum(V,0,index1);
		 ans+=maxSubArraySum(V,index2+1,n);
		 cout<<ans<<endl;
			}
	
}
