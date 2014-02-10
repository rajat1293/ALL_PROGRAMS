#include<iostream>
using namespace std;
class base
{
	protected:
		int name,roll;
		public:
			base(int a ,int b):name(a),roll(b)
		{
		}
		void raj()
		{
			cout<<"HELLO\n";
		}
					
};
class der :public base
{
	private:
		int sec,branch;
		public:
			der(int c,int d,int a,int b):base(a,b)
			{
				sec=c;branch=d;}
		void raj()
		{
			cout<<"HELLOwwww\n";
		}
		
			void display()
			{
				cout<<sec
				    <<branch
				    <<name
				    <<roll<<endl;
				    raj();
			}
};
int main()
{
	der ob(1,2,3,4);
	ob.display();
	ob.raj();
}
//THE BIG QUESTION IS WHY DO WE REQUIRE RUNTIME POLYMORPHISM
//IN THIS WE CANT DETERMINE WHITCH FUNCTION WILL RUN EVEN 

