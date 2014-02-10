//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<map>
#include<utility>
#include<queue>
#include<cstdio>
#include<cmath>
#include<stack>
#include<algorithm>
map<int,bool> prime;
map<int,bool> arr;

void markMultiples( int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
void SieveOfEratosthenes(int n)
{
	n=10;
prime[0]=0;
prime[1]=0;
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
       
 //       memset(arr, 0, sizeof(arr));
        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
               prime[i+1]=1;
                markMultiples( i+1, n);
            }
            else
            prime[i+1]=prime[i];
        }
    }
}

int poww(int n,int m) 
{ 
  	if(m==0) return (1);
   	int x=poww (n,m/2);
    if(m%2==0) return (x*x); 
	else return (((x*x))*n) ;
}
int digi(int i)
{
	int r;
	while(i>0)
{
	r=i%10;
	i=i/10;
	if(r==4||r==7)
	return 1;
}
return 0;
}
int main()
{
	SieveOfEratosthenes(1);
	int fact[50];
	int t,n;				
	cin>>t;
	while(t--)

{ 
	map<int,bool> check;
	map<int,bool> dig;
	int countt=0,i=2,ind=0;
	cin>>n;
	while(n!=1)
{
	if(n%i==0)
{
	fact[ind++]=i;
	n=n/i;
}
	else
	i++;
}
	int m=1;
	for(int j=1;j<poww(2,ind);j++)
{	
	m=1;
	for(int k=0;k<=ind-1;k++)
{
	if(	j&(1<<k))
{
	m=m*fact[k];
//	cout<<m;
}
}
	if((dig[m]&&check[m]==0)||(check[m]==0&&digi(m)))
{
	
	countt++;
	dig[m]=1;
}
check[m]=1;
}
	cout<<countt<<endl;
//for(int i=0;i<ind;i++)
//cout<<fact[i]<<" ";
}
}
