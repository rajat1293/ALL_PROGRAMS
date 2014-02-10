#include<stdio.h>
 //PURE DP
 long long max( long long x,  long long y)
{ return (y > x)? y : x; }
 
 long long maxSubArraySum(long long a[], long long size)
{
    long long max_so_far = a[0], i;
    long long curr_max = a[0];
 //ITS INCLUDING IT THE MAXIMUM CURR_MAX LIKE THAT OF THE LIS OR ELSE STORE IT IN AN ARAY
   for (i = 1; i < size; i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
      max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
  //	return curr_max;
}
 
/* Driver program to test maxSubArraySum */
int main()
{
   long long arr[100003];
   long long b[100003];
   long long int sum=0;
   long long t;
   scanf("%lld",&t);
   while(t--)
   {
    long long n;
   	scanf("%lld",&n);
   	for( long long i=0;i<n;i++)
   	{
   		scanf("%lld",&arr[i]);
   		b[i]=-arr[i];
   		sum+=arr[i];
   }
   long long  max_sum = maxSubArraySum(b, n);
  if(max_sum<0)
   printf("%lld\n",(long long)(sum));
  else
   printf("%lld\n",(long long)(sum+(2*max_sum)));
   }
}
