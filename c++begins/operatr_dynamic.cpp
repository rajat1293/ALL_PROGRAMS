#include<iostream>
using namespace std;
#include<stdlib.h>
#include<process.h>
class intarr
{ 
   private:
	int *p,h;
	public:
	intarr(int a)
	{h=a;
	cout<<"dddd"<<a<<"ddd";
		p=new int[a];
		for(int i=0;i<a;i++)
		p[i]=0;
	}
	void* operator new(size_t size)//since it is inside class it allocates 
	//memory for type of class objects only and same applies for delete.
	{
			
		void *l;
		l=malloc(size);//value of size is 8 and not 5,5 is for the constructor
		//and 8 comes from the fact that we have 2 values to be initialised
		if(!l)
		{cout<<"no memory allocated ";
		exit(1);
		}
		
	}
	void operator delete (void *l)
	{
		cout<<endl<<"deleted"<<endl;
		free(l);
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
	
	main()
	{ 
		intarr *c;
		c= new intarr(5);//intialisation takes place impicitly no explicit 
		//definition like for new is required..
		int *k;
		k=new int ;
	//	cout<<"enter the no of elements u want in the member\n";
	//	int a;
	//	cin>>a;
		//error handling needs to be done as c[7] will get anything
		(*c)[4]=3;
		cout<< (*c)[1];
		for(int i=0;i<5;i++)		
		cout<<endl<<(*c)[i];
		delete(c);
		delete (k);//no delete for thisss....
	}	//compiler knows when is address required and wheb\n
