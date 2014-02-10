#include<iostream>
using namespace std;
	class complex
	{
		private:
	int real,imag;
	public:
		friend complex operator +(int ,complex );
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
		//	cout<<"\nd"<<real;	
		}
		complex operator + (int cobj)
	{
//	cout<< "vvvv"<<real;
			int a=cobj+real;
			int b=cobj+imag;
	//herre an imp concept revealed is that the destructor
	//of even the object passed as a parameter would be 
		//destroyed also of temporary variale(t)
		return complex(a,b);//NAYA STYLE
		
		
	}
	complex operator + (complex cobj)
	{
//	cout<< "vvvv"<<real;
			complex t(0,0);
		t.real=cobj.real+real;//herre an imp concept revealed is that the destructor
		t.imag=cobj.imag+imag;//of even the object passed as a parameter would be 
		//destroyed also of temporary variale(t)
		return t;
		
		
	}
	complex operator ++ ()
	{
		real=real+1;
		return *this ;//*(this) pointer can be returned ....
				
	}
	complex operator ++ (int)
	{
		complex temp;
		temp.imag=imag;
		temp.real=real;
		imag =imag+1;
		return temp;		
	}
//	complex add(complex cobj)//we can make two diffrenet constructors for
	// objects of same class
//	{
//		complex t(0,0);
//		t.real=cobj.real+real;//herre an imp concept revealed is that the destructor
//		t.imag=cobj.imag+imag;//of even the object passed as a parameter would be 
		//destroyed also of temporary variale(t)
//		return t;		}
void display()
    {
	if (imag>=0)
	cout<< real<<"+"<<imag<<"i";
	else if(imag<0)
	cout <<real<<imag<<"i";
		
}	};
complex operator+(int a,complex cobj)
{
	complex cobj1;
	cobj1.real=a+cobj.real;
	cobj1.imag=a+cobj.imag;
	return cobj1;	
}
	main()
	{
		int a,b,c,d;
cout<<"enter the complex u want to cal the addition on\n";
cin>>a>>b>>c>>d;
complex cobj2(c,d),cobj1(a,b),c3,c5,c7;
    c3=cobj2+cobj1;//the left one is main object while right one is parameter
c3.display();
complex c9(5,6);
c5=c9+5;//const addition 
// tHIS IS NOT POSSIBLE AS LEFT IF THE CALLING FUNC AND RIGHT IS ARGUMENT
//SO WE NEED FRIEND FUNCTION...(c5=5+c9;)
c5.display();
c5=5+c9;
c5.display();
cout<<"\nenter another complex no";
cin>>a>>b;
complex c4(a,b);
c5 = ++c4;//real part is incremented by one(our iinterpretation)
c5.display();
cout<<"\nenter another complex no";
cin>>a>>b;
complex c6(a,b);	
c7=c6++;
c7.display();
cout<<endl;
c6.display();//the original is incremented by 1(note only img part incremented
//our choice ,it wass...
	}
	//THE FRIEND CAN BE USED FOR OVERLOADING OF ++ ALSO BUT THEN U MAKE SURE OF IMPLICIT
	//REFERENCE PASSING
	
