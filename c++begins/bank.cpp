#include<iostream>
using namespace std;
class bank
{
	private:
		int current,saving;
		public:
			bank(int a,int b)
			{
				current=a;
				saving=b;				
			}
	void withdsav(int k)
			{
				saving =saving-k;	
			}
	void interest(int a)
			{
			int inte;
			inte=saving*10*a/100;
			saving =inte+saving;	
			}
void withdcur(int a,int r)
	{int ser;
		current =current-a;
		if(current<1000)
		{
			ser =100*r;
			current=current-ser;
		}
		
		
	}
	void display()
	{
		cout<<saving<<endl;
		cout<<current<<endl;
		
		
	}
	
};
main()
{
	bank ob(5000,6000);
	ob.display();
	ob.withdsav(3000);
	ob.withdcur(4500,1);//1 represents time and this time has passed for
	//minimum balance
	ob.interest(3);
	ob.display();
	
	}
