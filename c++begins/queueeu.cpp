#include<iostream>
using namespace std;
#include<stdlib.h>
#define size 3
class queue
{
	
	private:
		int arr[size],front,rear;
		public:
			void init()
			{
			front=0;
			rear=0;
			}
	void addq(int element)
		{int k=rear;
			rear=(rear+1)%size;
			if(rear==front)
			{
			cout<<"queue is full\n";
			rear=k;
		}
			else
			arr[rear]=element;
		cout<<rear;	
		}	
		int deleteq()
		{cout<<front;
		if(front==rear)
		return -1;
		else
		front =(front+1)%size;
		return arr[front];	
		}
			};
			
	main()
	{
		queue stk1;
		stk1.init();
		int a,n,element;
		while(1)
		{
			cout<<"1.to add an element\n";
			cout <<"2.to delete an element\n";
			cout <<"enter choice\n";
			cin >>n;
			switch(n)
			{case 1:
				cout <<"enter the element to be added greater than 0\n";
				cin >>element;
			stk1.addq(element);
			break;
		case 2:
			element = stk1.deleteq();
			if(element==-1)
				cout<<"queue is empty\n";
				else
			cout<< "the deleted element is"<<element<<"\n";
			break;
			default :
				cout<< "wrong choice exiting";
				exit(2);
			
		}
		
	}
		
	}
			
			
