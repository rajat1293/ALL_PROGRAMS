#include<iostream>
using namespace std;
#include<stdlib.h>
#include<process.h>
class intarr
{ 
   private:
	int *p,h;
	public:
	intarr(int a)//a is the size of the memory allocated to p
	{h=a;
	cout<<"dddd"<<a<<"ddd";
		p=new int[a];
		for(int i=0;i<a;i++)
		p[i]=0;
}
		
	
	
	int& operator [] (int a)//& is used so that address is returned to for statements
	//like c[5]=4 type could be used
	{

	
	if(a>=0 || a<h)
	{
	return p[a];		
	}
	else
	cout<<"wrong choice\n";
	}
};	//this program overloads [] for printing the elemnts of the class,which get 
	//emory allocated dynimically
	
	void operator delete (void *l)
	{
		cout<<endl<<"deleted"<<endl;
		free(l);
	}
		void* operator new(size_t size)//since it is inside class it allocates 
	//memory for type of class objects only and same applies for delete.
	{
			
		void *l;
		l=malloc(size);//value of size is 8 and not 5,5 is for the constructor
		//and 8 comes from the fact that we have 2 values to be initialised
		if(!l)
		{cout<<"no memory allocated ";
		exit(8);
		}}
		void raj(intarr k)
		{
			cout<<"\nconquered\n";
			
		}
	main()
	{ 
		intarr *c;//object is also created dynamically.
		intarr d(5);
		c= new intarr(5);
		int *k;
		k=new int;
	//	cout<<"enter the no of elements u want in the member\n";
	//	int a;
	//	cin>>a;
		//error handling needs to be done as c[7] will get anything
		(*c)[4]=3;
		d[4]=9;
		raj(d);
		cout<< (*c)[1];
		for(int i=0;i<5;i++)		
		cout<<endl<<d[i];
		delete(c);
		delete(k);	//this delete works as new and delete are outside
	}	//compiler knows when is address required and when value
	//this is tthe beauty.....
	//ISSUES
	//1.the implicit memory deletion does not take place..??????
	//
	
