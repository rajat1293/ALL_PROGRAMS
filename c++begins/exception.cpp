#include<iostream>
#include<process.h>
using namespace std;
void fun(int x,int a,int b)
{try
{
	if(x==1)
	{
		cout<< a+b<<endl;
		return ;
		
	}
	else if(x==2)
	{
		if(a<b)
		throw 2;
		else 
		{
		cout<<a-b<<endl;
	return ;	
	}
	}
	else if(x==3)
{
	cout<< a*b<<endl;
	return ;
	}
	else if(x==4)
	{
		if(b==0)
		throw 4;
		else {
			cout<<a/b<<endl;
			return;
		}
	}
		else 
		{
		throw 10.3;}
		
	}
catch(int x)
{
	switch(x)
	{
		case 2:
			cout<<"INVALID NUMBERS to SUBTRACT\n";
			break;
			case 4:
				cout<<"CANNOT DIVIDE BY ZERO\n";
				break;
       // case 10:
        //	cout<<"invalid choice\n";
	}
}
	catch(...)
	{
			cout<<"invalid choice\n";
	}
}
int main()
{
	
	while(1)
	{
		cout<<"1.for addition\n"
	<<"2.for subtraction\n"
	<<"3.for multiplication\n"
	<<"4.for division\n"
	<<"5.to exit\n";
	int choice,a,b;
	cin>>choice;
		cout<<"\nenter two numbers\n";
		cin>>a>>b;
		switch(choice)
		{
			case 1:
				fun(1,a,b);
				break;
				case 2:
					fun(2,a,b);
					break;
					 case 3:fun(3,a,b);
					 break;
					 	 case 4:fun(4,a,b);
					 	 break;
					 	 	 case 5:cout<<"exiting...\n";
					 	 	 exit(3);
					 	 	 break;
					 	 	 	default:fun(choice,a,b);
					 	 	 	
			
		}
		
		
	}
	
	
}

//problem is that the choices are checked after enteriing the numbers
