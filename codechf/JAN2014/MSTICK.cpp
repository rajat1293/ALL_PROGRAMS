#include<iostream>
typedef unsigned long long ull;
using namespace std;
ull mulmod(ull a,ull b,ull c){
	ull x=0,y=a%c;
	while(b>0){
		if(b%2==1){
			x=(x+y)%c;
		}
		y=(y*2)%c;
		b /=2;
	}
	return x%c;
}
void print(ull L, ull x,ull y,ull c){
	ull ans;
	ans= mulmod(L,y,c);
	ans = (ans + x)%c;
	cout<<ans<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		char str[1002];
		ull  arr[1003];
		ull  n;
		cin>>n;
		for(ull i=0 ;i< n;i++)
		cin>> arr[i];
		ull a,b,c;
		cin>>a>>b>>c;
		cin>>str;
		int i=0,j=n-1;
		ull x=0,y=1;
		int index=0;
		bool flag=false;
		while(index<n)
		{
		//	cout<<str[index];
			if(str[index]=='A')
				{
					x= (x + a)%c;	
				}
				
			 else if(str[index]=='M')
			 	{
			 		y = mulmod(y,b,c);
			 		x = mulmod(x,b,c);
			 		
			 	}
			else if(str[index]=='R')
			{
				if(flag == false)
				{
				 print(arr[j],x,y,c);
				 j--;
				 flag=true;
				}		
				else{
					print(arr[i],x,y,c);
					i++;
					flag=false;	
				}
				index++;
				continue;
			}
			
			if( flag == false ){
				print(arr[i],x,y,c);
				i++;
			}
			else{
				print(arr[j],x,y,c);
			 	j--;	
			}
			index++;
		}
		cout<<"\n";
		
	}	
}

