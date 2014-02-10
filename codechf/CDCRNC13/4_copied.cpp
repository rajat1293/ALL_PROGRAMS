#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		char a,b;
		cin>>a>>b;
		
	
	if(((a>=49 && a<=57)||(a==65 || a==75 || a==81 || a==74)) && ((b>=49 && b<=57)||(b==65 || b==75 || b==81 || b==74)))
	
	{
		char first=a;
		char second=b;
		int sum=0;
		if((first==75 && second==75)||(first==81 && second==81)||(first==74 && second==74)||(first==65 && second==65))
		cout<<"STAND\n";
		else{
		//for first card
		if(first>=49 && first<=57)
		sum=sum+(first-48);
		else if(first==75 || first==81 || first==74)
		sum=sum+10;
		
		//for second card
		if(second>=49 && second<=57)
		sum=sum+(second-48);
		else if(second==75 || second==81 || second==74)
		sum=sum+10;
		
		//checking condition
		if(sum<=11 || first==65 || second==65)
		cout<<"HIT\n";
		else
		cout<<"STAND\n";
}
	}
		else
		cout<<"INVALID\n";
}
	
	
}
