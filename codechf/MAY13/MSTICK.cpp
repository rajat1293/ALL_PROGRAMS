// Program for range minimum query using segment tree
#include<iostream>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#ifndef ONLINE_JUDGE
inline int getchar_unlocked() { return getchar(); }
#endif


using namespace std;
//-----------------MAX VALUE---------------------------
int maxVal(int x, int y) { return (x > y)? x: y; }
int getMid(int s, int e) {  return s + (e -s)/2;  }
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MIN;
    int mid = getMid(ss, se);
    return maxVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
int RMQ(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        //printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  maxVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}
//-----------------------------------------------------

//------------------MIN VALUE-------------------------
int minVal(int x, int y) { return (x < y)? x: y; }
int RMQUtil2(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return minVal(RMQUtil2(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil2(st, mid+1, se, qs, qe, 2*index+2));
}
int RMQ2(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        //printf("Invalid Input");
        return -1;
    }
 
    return RMQUtil2(st, 0, n-1, qs, qe, 0);
}
int constructSTUtil2(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil2(arr, ss, mid, st, si*2+1),
                     constructSTUtil2(arr, mid+1, se, st, si*2+2));
    return st[si];
}
int *constructST2(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
    constructSTUtil2(arr, 0, n-1, st, 0);
    return st;
}
int main()
{
    int arr[100005];
	int n ;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int *st = constructST(arr, n);
	int *st2 = constructST2(arr,n);
	int Q;
	cin>>Q;
	while(Q--){
    int qs ;  // Starting index of query range
    int qe  ; // Ending index of query range
    cin>>qs>>qe;
    int maxx2=0;
    int maxx=RMQ(st, n, qs, qe);
    int minn = RMQ2(st2, n, qs, qe);
    if(qs>0)
    	maxx2=RMQ(st,n,0,qs-1);
    if(qe<n-1)
    {
    	int val=RMQ(st,n,qe+1,n-1);
    	if(val>maxx2){
    		maxx2=val;
    	}
    }
    double ans1= minn+maxx2;
    double ans2 = minn+ (double)(maxx-minn)/2;
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(1);
    if(ans1>ans2)
    cout<<ans1<<endl;
    else
    cout<<ans2<<endl;
}
}
