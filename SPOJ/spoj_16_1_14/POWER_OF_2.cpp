#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	// to  check if n is a power of 2
	if(n==0){
		cout<<"no";
		return 0;
	}
	if((n&(n-1))==0){
		cout<<"yes";
	}
	else
	cout<<"no";

}
