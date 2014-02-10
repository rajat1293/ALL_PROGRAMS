#include<iostream>
#include<cmath>
using namespace std;
// generating all possible subsets of a set
int main(){
	int n;
	cin>>n;
	for(int i=0;i<pow(2,n);i++)// this implies the number to be used as  a bit pattern
	{
		for(int j=n-1;j>=0;j--) // this implies the live bits in the number( basicallly the mask)
		if(i&1<<j)
		cout<<"1";
		else
		cout<<"0";
		cout<<endl;
	}	
}
