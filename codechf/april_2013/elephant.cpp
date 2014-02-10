//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

	
int patti(int * a,int p,int r)
{
     int x,i,j,t,k;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++)
        {
        if(a[j]<=x)
        {
            i=i+1;
            t=a[i];
            a[i]=a[j];
            a[j]=t;        
        }
    }
            k=a[i+1];
            a[i+1]=a[r];
            a[r]=k;
            return (i+1);

}
int qrsort(int a[],int p,int r)
{
int q ;
if(p<r)
  {

   q = patti(a,p,r);
   qrsort(a,p,q-1);
   qrsort(a,q+1,r);}
}

int main()
{
		int B[100009];
		int L[10009];
	int i,t;
	cin>>t;
	while(t--)
	{
	int sum=0;
	int N;
	cin>>N;
	for( i=0;i<N;i++)
	cin>>B[i]>>L[i];
	qrsort(B,0,N-1);
	qrsort(L,0,N-1);
	for( i=0;i<N;i++)
	{
		sum+=B[i]*L[i];		
	}
	cout<<sum<<endl;	
}
}
