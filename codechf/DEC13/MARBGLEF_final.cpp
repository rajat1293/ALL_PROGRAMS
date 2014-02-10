#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int Edit[10][10];
 int Ed(int m,int n,string s1,string s2)
{
for(int i = 1 ;i<= m;i++)	
{
	for(int j = 1 ;j<= n;j++)
{
//	cout<<s1.at(0);
if (s1.at(i-1) == s2.at(j-1))
Edit[i][ j] =min(min(Edit[i-1][ j]+1,Edit[i][ j -1]+1),Edit[i -1][ j -1]);
else
Edit[i][j] =min(min(Edit[i -1][ j]+1, Edit[i][ j -1]+1), Edit[i -1][ j -1]+1);
//cout<<Edit[i][j]<<" ";
//cout<<endl;
}
}
return Edit[m][n];
}
long long  getMid(long long  s, long long  e) {  return s + (e -s)/2;  } 
long long  getSumUtil(long long  *st, long long  ss, long long  se, long long  qs, long long  qe, long long  index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return 0;
 
    long long  mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
void updateValueUtil(long long  *st, long long  ss, long long  se, long long  i, long long  diff, long long  index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        long long  mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 int ddEd(int m,int n,string s1,string s2)
{
for(int i = 1 ;i<= m;i++)	
{
	for(int j = 1 ;j<= n;j++)
{
//	cout<<s1.at(0);
if (s1.at(i-1) == s2.at(j-1))
Edit[i][ j] =min(min(Edit[i-1][ j]+1,Edit[i][ j -1]+1),Edit[i -1][ j -1]);
else
Edit[i][j] =min(min(Edit[i -1][ j]+1, Edit[i][ j -1]+1), Edit[i -1][ j -1]+1);
//cout<<Edit[i][j]<<" ";
//cout<<endl;
}
}
return Edit[m][n];
}
void updateValue(long long  arr[], long long  *st, long long  n, long long  i, long long  new_val)
{
    if (i < 0 || i > n-1)
    {
        return;
    }
    long long  diff = new_val - arr[i];
 
    arr[i] = new_val;
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
long long  getSum(long long  *st, long long  n, long long  qs, long long  qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
int fgEd(int m,int n,string s1,string s2)
{
for(int i = 1 ;i<= m;i++)	
{
	for(int j = 1 ;j<= n;j++)
{
//	cout<<s1.at(0);
if (s1.at(i-1) == s2.at(j-1))
Edit[i][ j] =min(min(Edit[i-1][ j]+1,Edit[i][ j -1]+1),Edit[i -1][ j -1]);
else
Edit[i][j] =min(min(Edit[i -1][ j]+1, Edit[i][ j -1]+1), Edit[i -1][ j -1]+1);
//cout<<Edit[i][j]<<" ";
//cout<<endl;
}
}
return Edit[m][n];
}
 
long long  constructSTUtil(long long  arr[], long long  ss, long long  se, long long  *st, long long  si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    long long  mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
long long  *constructST(long long  arr[], long long  n)
{
    long long  x = (long long )(ceil(log2(n))); 
    long long  max_size = 2*(long long )pow(2, x) - 1; 
    long long  *st = new long long [max_size];
 
    constructSTUtil(arr, 0, n-1, st, 0);
 
    return st;
}
 
int  main()
{
  long long  n,q;
  cin>>n>>q;
  long long  arr[n+2];
  for(long long  i=0;i<n;i++)
  cin>>arr[i];
  long long  *st=constructST(arr ,n);
  while(q--)
  {
  	char ch;
  	long long  a,b,nw;
	cin>>ch>>a>>b;
		
  	if(ch=='S')
  	{
  		cout<<getSum(st,n,a,b)<<endl;
  	}
  	else if(ch=='G')
  	{
  		nw=arr[a]+b; 
  		updateValue(arr,st,n,a,nw);
  	}
  	else
  	{
  		nw=arr[a]-b;
  		updateValue(arr,st,n,a,nw);
  	}
  }  
}

