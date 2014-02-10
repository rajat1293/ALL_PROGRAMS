//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
using namespace std;
float f(float x)
{
	return (cos(x)-x*exp(x));
}
void regula (float &x,float x0,float x1,float fx0,float fx1,int &itr)
{
x=x0-((x1-x0)/(fx1-fx0)*fx0);
++itr;
cout<<"iterator no "<<setw(3)<<itr
	<<"X = "<<setw(7)<<setprecision(5)<<x<<'\n';		
}
int main()
{
	int itr=0,maxitr;
	float x0,x3,x2,aerr,x1;
	cout<<"enter the values of x0 and x1 "<<
	"allowed error, maximum iterations"<< endl;
	cin>>x0>>x1>>aerr>>maxitr;  
	regula(x2,x0,x1,f(x0),f(x1),itr);
	cout<<fixed;
	do{
		
		if(f(x0)*f(x2)<0)
		x1=x2;
		else 
		x0=x2;
		regula(x3,x0,x1,f(x0),f(x1),itr);
		if(fabs(x3-x2)<aerr)
		{
			cout<<"After "<<itr<<"iterations,root"<<
			"="<<setw(6)<<setprecision(4)<<x3<<endl;
			return 0;
		}
		x2=x3;
	}while(itr<maxitr);
		
	cout<<"solutions do not converge,"<<
	"iterations not sufficient"<<endl;
	return 1;	
}
