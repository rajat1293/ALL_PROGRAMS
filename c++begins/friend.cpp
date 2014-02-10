#include<iostream>
using namespace std;
class c2;
class c1
{   private:
	int print;
	public:
	c1(int a)
	{
		print=a;
	}
	friend int prin_stat(c1,c2);
};
class c2
{   private:
	int print;
	public:
			c2(int a)
	{
		print=a;
	}
	friend int prin_stat(c1,c2);
			
};
int print_stat( c1 ob1,c2 ob2)
{
	if((ob1.print==0)&&(ob2.print==0))
	return 1;
	else return 0;
}
main()
{int k;
c1 ob1(0);
c2 ob2(1);
k=print_stat(ob1,ob2);
if(k==1)
cout<<"yes";
else cout<<"no";
}



	
	
	
}
