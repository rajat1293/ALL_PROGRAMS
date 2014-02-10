#include<iostream>
using namespace std;
#include<stdlib.h>
#define size 5
class stack
{
	private:
		int arr[size],top;
		public:
			void init()
			{top=-1;
			}
void push(int element)
		{
			if(top==size-1)
			cout<<"stack full\n";
			else 
			arr[++top]=element;
		}
	int pop()
	{
		if(top==-1)
		return -1;
		else 
		return arr[top--];
	}
};

	main()
	{cout<<sizeof(stack);
		stack stk1;
		stk1.init();
		int a,n,element;
		while(1)
		{
			cout<<"1.to push an element\n";
			cout <<"2.to pop an element\n";
			cout <<"enter choice\n";
			cin >>n;
			switch(n)
			{case 1:
				cout <<"enter the element to be pushed greater than 0\n";
				cin >>element;
			stk1.push(element);
			break;
		case 2:
			element =stk1.pop();
			if(element==-1)
				cout<<"stack is empty\n";
				else
			cout<< "the popped element is"<<element<<"\n";
			break;
			default :
				cout<< "wrong choice exiting";
				exit(2);
			
		}
		
	}
		
	}
	

	
