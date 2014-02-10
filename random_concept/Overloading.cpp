//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
#include<stdio.h>
//#include<math.h>
using namespace std;
void disp(){
	cout<<"1\n";
}
void disp(int a){
	cout<<"2\n";
}
int disp(int a){
	cout<<"3\n";
}
int main()
{
	disp();
    disp(3,4);
	disp(1);
}

