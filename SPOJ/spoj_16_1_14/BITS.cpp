#include<iostream>
using namespace std;
// this program calculates the 
//Given an integer x, return a number y with only the most significant bit in x set.
// It is same as the largest power of 2 that is no greater than x 
int main(){
	int n;
	cin>>n;
	int y=n;
	 y = y | ( y >>1 ) ;
	 cout<<y<<endl;    // SETTING EACH BIT STEP BY STEP    
	 y = y  | ( y >>2 );            
	 cout<<y<<endl;    // SETTING EACH BIT STEP BY STEP    
	
	 y = y  | ( y >>4 );           
	 cout<<y<<endl;    // SETTING EACH BIT STEP BY STEP    
	
	 y = y  | ( y >>8 );           
	 cout<<y<<endl;    // SETTING EACH BIT STEP BY STEP    
	
	 y = y  |  ( y >>16 ) ;
	cout<<y<<endl;
	 y=(y+1)>>1; 
	 cout<<y;		
}
// what we do here is that we make all the bits one and then we add one and then right shift
// by one to get the required  ANSWER
