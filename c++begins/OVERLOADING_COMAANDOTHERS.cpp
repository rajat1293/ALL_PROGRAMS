#include<iostream>
using namespace std;
	class complex
	{
		private:
	int real,imag;
	public:
		complex(int a,int b) : real(a),imag(b)
		{		
		}
		complex()
		{
				
		}
		
				~complex()
		{
		//	cout<<"\nd"<<real;	
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
		
}	
complex operator ,(complex c)
{
	int t=c.real+2;
	int k=c.imag+3;
	return complex(t,k);	
}


complex operator ()(int a,int b) //complex operator ()(int a,int b) : real(a),imag(b)
//ONLY CONSTRUCTOR ALLOW THIS
{
	real=a;
	imag=b;
	return *this;
}
complex *operator->()
{
	return this;
}

};
	main()
	{
		int a,b,c,d;
cout<<"enter the complex u want to cal the addition on\n";
cin>>a>>b>>c>>d;
complex cobj2(c,d),cobj1(a,b),c3,c5,c9,c10;
c3=(cobj2,cobj1);//A,B ARE PAASEESD AND INCREMENTED
c3.display();
c3=cobj2,cobj1;//SINCE NO BRACKETS SO NO COMMA COMING INTO PICTURE
//PRECENDECE BUDDY :)

   // c3=cobj2+cobj1;//the left one is main object while right one is parameter
c3.display();
c5=(c9(3,4),c10(1,2));//HERE C9 AND C10 ARE INITIALIZED WITH 
//THE HELP OF () OVERLOADING.. 
c5.display();
complex *c1;
c1=new complex;
(*c1)(3,4);
c1->display();
complex c2(1,9);
c2->display();

}
/*cout<<"\nenter another complex no";
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
	}*/
