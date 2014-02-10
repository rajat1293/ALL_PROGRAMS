//AUTHOR ---RAJAT GAMBHIR------
//DATE
//-----------
 int binary(int a[],int k,int low,int high)
{
                int mid,l;
                mid = (low+high)/2;
                if (low>high)
                return (low-1);
                else if(a[mid]==k)
                return mid;
                else if (a[mid]>k)
                {l=binary(a,k,low,mid-1);
                return l;}
                else {l=binary(a,k,mid+1,high);
                return l;}
}
//----------
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int a[]={0,4,7,9,14,23};
	cout<<binary(a,5,1,5);
}


