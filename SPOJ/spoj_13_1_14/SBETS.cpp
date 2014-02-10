#include<iostream>
#include<map>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int t;
	cin>> t;
	while(t--){
		 
		 map<string,int> m;
		 char tim1[5],tim2[5];
		 int gol1,gol2;
		for (int i = 0; i < 16; ++i) {
            scanf("%s %s %d %d", tim1, tim2, &gol1, &gol2);
			if(gol1>gol2){
				m[tim2]+=1;
				m[tim1]+=0;
			}
			else{
				m[tim1]+=1;
				m[tim2]+=0;
			}		
	}
	for(map<string,int>::iterator it = m.begin();it != m.end();it++){
		if(it->second==0)
	{
		cout<<it->first<<endl;
		break;
	}
		
		
	}
}
}
		
		

