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
		return t;		
}void display()
    {
	if (imag>=0)
	cout<< real<<"+"<<imag<<"i";
	else if(imag<0)
	cout <<real<<imag<<"i";
		
}	};
	main()
	{
		int a,b,c,d;
cout<<"enter the complex u want to cal the addition on\n";
cin>>a>>b>>c>>d;
complex cobj2(c,d),cobj1(a,b),c3;
    c3=cobj1.add(cobj2);
c3.display();		
	}
