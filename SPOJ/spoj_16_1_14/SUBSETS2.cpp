#include<iostream>
#include<cmath>
using namespace std;
// generating all possible subsets of a set
int main(){
	int n;
	cin>>n;
	int x=n;
	while(1){
		cout<<x<<endl;
		if(x==0)
		break;
		x=(x-1)&n;	
	}
	
}
