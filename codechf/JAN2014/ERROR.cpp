#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		
		char str[100004];
		cin>>str;
		if(strstr(str,"010")||strstr(str,"101"))
		cout<<"Good\n";
		else
		cout<<"Bad\n";
		
	}
}
