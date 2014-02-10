#include<iostream>
using namespace std;
#include<stdlib.h>
#define size 5


class mahastack 
{
class stack
{
	public:
		int arr[size],top,roll;
		public:
			stack()
			{top=-1;
			}
		void push(int element)
		{
			if(top==size-1)
			cout<<"stack full\n";//here 5 is added in stack
			else 
			arr[++top]=element;
	}
	void display()
	{
		cout<<endl<<arr[0];
			} 
	};
	stack a;

	public:
	void ds()
	{
			a.push(5);
		a.display();
		
	}
};
main()
{
	mahastack s;
	s.ds();
	
}
	
	

