//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
//choose a and such that the signs are opposite
#include<iostream>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
float f(float x)
{
	return x*x*x-4*x-9;
}
void bisect(float &x,float a,float b,int &itr) 
{
	x=(a+b)/2;
	++itr;
	cout<<"iterator no "<<setw(3)<<itr
	<<"X = "<<setw(7)<<setprecision(5)<<x<<'\n';
}
int main()
{
	int itr=0,maxitr;
	float x,a,b,aerr,x1;
	cout<<"enter the values of a and b "<<
	"allowed error, maximum iterations"<< endl;
	cin>>a>>b>>aerr>>maxitr;
	cout<<fixed;                                  //check
	bisect(x,a,b,itr);
	do{
		
		if(f(a)*f(x)<0)
		b=x;
		else 
		a=x;
		bisect(x1,a,b,itr);
		if(fabs(x1-x)<aerr)
		{
			cout<<"After "<<itr<<"iterations,root"<<
			"="<<setw(6)<<setprecision(4)<<x1<<endl;
			return 0;
		}
		x=x1;
	}while(itr<maxitr);
	cout<<"solutions do not converge,"<<
	"iterations not sufficient"<<endl;
	return 1;	
		}
	
//a and b are the limits in which the root lies
//aerr i the allowed error
//itr is the counter which keeps track of the number of iterations performed
//maxitr is max iterations to be performed
//x is root at nth iteration
//x1 is the value of root at n+1 th iteration
//PERFORMS AND PRINTS THE RESULT OF ONE ITERATION
//x is the result of currnt iteration
