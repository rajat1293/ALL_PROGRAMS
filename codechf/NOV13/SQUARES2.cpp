#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

long long HONEY[121]={0,
1,
4,
9,
49,
100,
144,
400,
441,
900,
1444,
4900,
9409,
10000,
10404,
11449,
14400,
19044,
40000,
40401,
44100,
44944,
90000,
144400,
419904,
490000,
491401,
904401,
940900,
994009,
1000000,
1004004,
1014049,
1040400,
1100401,
1144900,
1440000,
1904400,
1940449,
4000000,
4004001,
4040100,
4410000,
4494400,
9000000,
9909904,
9941409,
11909401,
14010049,
14040009,
14440000,
19909444,
40411449,
41990400,
49000000,
49014001,
49140100,
49999041,
90440100,
94090000,
94109401,
99400900,
99940009,
100000000,
100040004,
100140049,
100400400,
101404900,
101949409,
104040000,
104919049,
110040100,
111049444,
114041041,
114490000,
144000000,
190440000,
194044900,
400000000,
400040001,
400400100,
404010000,
404090404,
409941009,
414000409,
414041104,
441000000,
449440000,
490091044,
900000000,
990990400,
991494144,
994140900,
1190940100,
1401004900,
1404000900,
1409101444,
1444000000,
1449401041,
1490114404,
1990944400,
4014109449,
4019940409,
4041144900,
4199040000,
4900000000,
4900140001,
4901400100,
4914010000,
4914991449,
4941949401,
4999904100,
9044010000,
9409000000,
9409194001,
9410940100,
9900449001,
9940090000,
9994000900,
9999400009,
10000000000
};
 long long bin(long long int* a,long long k,long long low,long long  high)
{
                long long mid,l;
                mid = (low+high)/2;
                if (low>high)
                return 0;
                else if(a[mid]==k)
                return mid;
                else if (a[mid]>k)
                {l=bin(a,k,low,mid-1);
                return l;}
                else {l=bin(a,k,mid+1,high);
                return l;}
}
bool check(long long p)
{
	while(p>0)
	{
		long long r=(p%10);
		if(r!=0&&r!=4&&r!=9&&r!=1)
		return false;
		p=p/10;
	}
	return true;
}
 long long binary(vector<long long>& a,long long k,long long low,long long  high)
{
                long long mid,l;
                mid = (low+high)/2;
                if (low>high)
                return (low);
                else if(a[mid]==k)
                return mid;
                else if (a[mid]>k)
                {l=binary(a,k,low,mid-1);
                return l;}
                else {l=binary(a,k,mid+1,high);
                return l;}
}
int main()
{
	vector<long long > arr(100003);
	for(long long i=1;i<=100001;i++)
{
	arr[i]=i*i;
//	cout<<arr[i]<<" ";
}
	long long  t;
	scanf("%lld",&t);
	while(t--)
{
	long long i=0;
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long low=binary(arr,a,1,100000);
	long long p=arr[low];
	while(p<=b)
	{
	if(bin(HONEY,p,1,120))	
		{
		i++;
	//	cout<<p<<","<<endl;
		}
		++low;
		p=arr[low];
	}
	printf("%lld\n",i);
}
}
