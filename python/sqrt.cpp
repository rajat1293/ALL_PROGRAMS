//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	float n,a;
	cout<<"\nenter number you want to find sqrt of";
	cin>>n;
	cout<<"\nenter the approx value for sqrt of number ";
	cin>>a;
	int i=0;
	while(1){
		i++;
   if(fabs(a*a-n)<=0.00001)
{
	cout<<"\nthe sqrt is "<<a;
    cout<<"\niterations used is "<<i;
	 break;
}
	else 
	a=(a+n/a)/2;
}
}
//Heron
//of
//Alexandria
