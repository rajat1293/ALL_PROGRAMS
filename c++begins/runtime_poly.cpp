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
		base():name(0),roll(0)
		{
		}
 virtual void raj()
		{
			cout<<"HELLO\n";
		}
					
};
class der :public base
{
protected:
		int sec,branch;
		public:
				der():sec(0),branch(0)
				{
				}
		void raj()
		{
			cout<<"ELLOwwww\n";
		}
		
			void display()
			{
				cout<<sec
				    <<branch
				    <<name
				    <<roll<<endl;
			}
};
class der2 :public der
{
		public:
			der2()
			{
				}
		/*void raj()
		{
			cout<<"HELLOwwww\n";
		}*/
		
			void display()
			{
				cout<<sec
				    <<branch
				    <<name
				    <<roll<<endl;
			}};
int main()
{
	base *p,b;
	der2 d;
	p=&d;
   p->raj();
   	
}
//THE BIG QUESTION IS WHY DO WE REQUIRE RUNTIME POLYMORPHISM
//IN THIS WE CANT DETERMINE WHITCH FUNCTION WILL RUN EVEN 
//WHEN THE VALUES TO BE INITIALSED ARE NULL THEN THE CONSTRUOR WITH NO
// WOULD WORK AUTOMATIICALLY
//APPLIYING NO VIRTUAL KEYWORD PRODUCES NO ERROR 
// BUT THE POLYMOPHISM IS NOT FOLLOWED.
//P->raj(),GUVES SAME RESULT AS P->RAJ &&P=&B;
//THAT  IS FUNCTION OF BASE IS PRINTED IN BOTH THE CASSES..
