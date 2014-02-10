//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
	class A{
		int a;
		public:
			A(){
				cout<<"\nyes";
			}
		void A(int i,float j){
				cout<<"\nyes1";
}
 void A(float j,int i){
				cout<<"\nyes2";
}
};
int main()
{

A ob;
ob.A(3,2.3);
}
