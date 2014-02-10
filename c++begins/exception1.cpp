//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<process.h>
using namespace std;
int fun(int a,int b) throw (int,double)
{


	if(b==0)
	throw 2.1;
	else 
	throw 2;


}
int main()
{
	int a,b;
	cout<<"entr two numbers\n";
	cin>>a>>b;
	try{
	fun(a,b);
	}
	catch(double a)
	{cout<<"fus fus";
	}
	catch(...)
	{cout<<"no catch found\n";
}
}
//checking the rethrow ,unfinished
//ACTUALLY THAT SPECIFICATION OF THROW COMES INTO PICTURE WHEN THERE IS A THROW FROM CATCH OF
//THAT FUNCTION TO OUTSIDE..ELSE IT IS NOT MUCH OF AN ISSUE..
//a try block neesds to have a catch block and 
//SINCE THE  FUNCTIN WAS WITHIN THE TRY BLOCK WE  DONT NEED A TRY BOCK THERE NECESSARILY....
