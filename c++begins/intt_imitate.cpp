#include<iostream>
using namespace std;
#include<string.h>
class intt 
{private:
	int a;
	public :
		intt()
		{
			a=0;
		}
		void set(int jj)
		{
			a=jj;
			
		}
	intt add(intt c)
	{
		intt b;
		b.a=a+c.a;
		return b;
		
	}
void	display()
	{
		cout<<a<<endl;
	}
};
main()
{int a,b;
	intt aa,bb,cc;
	cout<<"enter two numbers a and b\n";
	cin >>a>>b;
	aa.set(a);
	bb.set(b);
	aa.display();
	bb.display();
cout<<"\nthe additon is";
cc=aa.add(bb);
cc.display();
}
