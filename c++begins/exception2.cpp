//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<process.h>
using namespace std;
int fun(int a,int b) 
{
	try{
	
	if(b==0)
	throw 2.4;
	else if(b==1)
	throw 2;
	else 
	return a+b;
} 
catch(double a)
{
cout<<"function catch\n";
return 0;
}
catch(...)
{cout<<"no\n";
throw;
}
}
int main()
{
try
{
	int a,b;
	cout<<"entr two numbers\n";
	cin>>a>>b;
	int f=fun(a,b);
	cout<<f;}
	catch(int a)
	{
		cout<<"yes its here\n";
	}
}
//catch can retun a value using return which is utilised here
