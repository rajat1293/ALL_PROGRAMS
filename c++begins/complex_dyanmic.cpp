#include<iostream>
using namespace std;
#include<stdlib.h>
#include<process.h>
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
		//	cout<<endl<<"pp"<<endl;	
		}		
	~complex()
		{
			cout<<endl<<"des"<<endl;	
		}
	
	complex add(complex cobj)//we can make two diffrenet constructors for
	// objects of same class
	{
		complex t(0,0);
		t.real=cobj.real+real;//herre an imp concept revealed is that the destructor
		t.imag=cobj.imag+imag;//of even the object passed as a parameter would be 
		//destroyed also of temporary variale(t)....but no constructor for
		//the passed variable.(cobj)....
		return t;		
}void display()
    {
	if (imag>=0)
	cout<< real<<"+"<<imag<<"i";
	else if(imag<0)
	cout <<real<<imag<<"i";
		
}};	
	
		void* operator new (size_t size)//since it is inside class it allocates 
	//memory for type of class objects only and same applies for delete.
	{
			cout<<endl<<size<<endl;	
		void *l;
		cout<<endl<<"alloo"<<endl;
		l=malloc(size);//value of size is 8 and not 5,5 is for the constructor
		//and 8 comes from the fact that we have 2 values to be initialised
		if(!l)
		{cout<<"no memory allocated ";
		exit(8);
		}}
		void operator delete (void *l)
	{
		cout<<endl<<"deleted"<<endl;
		free(l);
	}

	main()
	{
		int a,b,c,d;
cout<<"enter the complex u want to cal the addition on\n";
cin>>a>>b>>c>>d;
complex cobj2(c,d),cobj1(a,b),c3;
    c3=cobj1.add(cobj2);
    c3.display();
    complex c4;
   // cout<<c3;
complex *p;
p=new complex[4];
//delete(p);//here an array of objects is created with 4 elemenets 
//no intialisation has been done soo far..		
	}
	//SOME IMPORTANT CONCLUsIONS AND OBSERVATIONS and doubts
	/*
	1.now ,the constructor intialises  while the destructor frees the memory
	,but the delete also frees the memory...
	2.when i used the delete for the dynamically allocated memeory
	for the p (complex type) its destructor also ran.but when i removed 
	it no DESTRUCTOR RAN.
	3.for the int type a,b,c,d when new and delete were outside the
	class there delete ran consecutively after there intiallisaton..
	why did this happen,i meean delete was not for a,b...as they were not 
	allocated dynamicallly....
	4.as said by sir [] are required for dynamic allocation of arr of 
	complex but its working fine without it.even 
	5.WITH DESTRUCTOR SIZE GIVEN IS 36 ELSE 32
	6.no delete runs for [] case and only destructor
	7.13 is the size of the integers....
	8.no destructor runs when delete is removed...for p(commplex type)
	DESTRUCTOR RUNS ONLY FOR THOSE WHO R NOT DECLAERD DYNAMICALLY
	*/ 
