#include<iostream>
using namespace std;
	class complex
	{
		private:
	int real,imag;
	public:
		complex(int a,int b)
		{
			real=a;
			imag=b;			
		}
		complex()
		{
				
		}
		
				~complex()
		{
			cout<<"\nd"<<real;	
		}
	
	complex add(complex cobj)//we can make two diffrenet constructors for
	// objects of same class
	{
		complex t(0,0);
		t.real=cobj.real+real;//herre an imp concept revealed is that the destructor
		t.imag=cobj.imag+imag;//of even the object passed as a parameter would be 
		//destroyed also of temporary variale(t)but no constructor for
		//the passed variable.(cobj)....
		return t;}	
		friend 	ostream& operator<<(ostream& ost,complex a); 
		friend istream& operator>>(istream &ist,complex& a);
		};
		ostream& operator<<(ostream &ost,complex a){
		if(a.imag>=0)
		ost<<a.real<<"+"<<a.imag<<"i";
		else 
		ost<<a.real<<a.imag<<"i";
		return ost;
		}
		istream& operator>>(istream &ist,complex& a)
		{
			ist>>a.real>>a.imag;	
		}
int	main()
	{
cout<<"enter the complex u want to cal the addition on\n";
complex cobj2,cobj1;
cin>>cobj2>>cobj1;
cout<<cobj1<<endl<<cobj2;
return 0;	
	}
