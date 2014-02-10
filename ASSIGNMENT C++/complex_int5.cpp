#include<iostream>
using namespace std;
class complex;
class integer
{
	int n;
	public:
	integer(int k=0):n(k)
	{
	}
friend complex convrt(integer);
	friend integer convrt(complex );
	friend int operator +(complex ,integer);	
	void disp(){
		cout<<n<<endl;
	}
};
class complex
{
	int real,imag;
	public:
	complex(int r=0,int i=0):real(r),imag(i)
	{
	}
	friend complex convrt(integer);
	friend integer convrt(complex );
	friend int operator +(complex ,integer);	
void disp()
{if(imag>=0)
cout<<real<<" + "<<imag<<"i"<<endl;
else 
cout<<real<<imag<<"i";
}
};
integer convrt(complex ob)
{
int a=ob.real+ob.imag;
return integer(a);	
}
complex convrt(integer s)
{
int a=s.n;
int b=s.n;
return complex(a,b);
}
int operator +(complex ob,integer s)
{
	int a=s.n+ob.real+ob.imag;
return a;
}
int main()
{
	
	complex d=complex(5,6);
	integer s(3);
	complex d2;
	d2=convrt(s);
	d2.disp();
	integer s2;
	s2=convrt(d);
	s2.disp();
	cout<<d+s;
	return 0;
}








