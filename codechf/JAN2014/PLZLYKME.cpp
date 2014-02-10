#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		
		long l,d,s,c;
		cin>>l>>d>>s>>c;
		long long ans=s;
		if(s>=l){
			cout<<"ALIVE AND KICKING\n";
			continue;
		}
		for(long long i=2;i<=d;i++){
			ans += ans*c;
			if(ans>=l){
					cout<<"ALIVE AND KICKING\n";
					break;
			}
		}
		if(ans<l)
		cout<<"DEAD AND ROTTING\n";
	}
	
	
}
