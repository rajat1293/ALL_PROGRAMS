#include<iostream>
using namespace std;
class poly
{
	private:
		int coef[4],expo[4];
	public:
		poly(int a,int b)
		{
			coef[0]=a;
			expo[0]=b;
		}
	~poly()
	{
	}
poly operator + (poly ob)
	{poly k(0,0);
		if(ob.expo[0]==expo[0])
	{	k.coef[0]=ob.coef[0]+coef[0];
	k.expo[0]=expo[0];}
		else if (ob.expo[0]>expo[0])
		{
			k.expo[0]=ob.expo[0];
			k.coef[0]=ob.coef[0];
			k.expo[1]=expo[0];
			k.coef[1]=coef[0];
		}
		else{
		
		k.expo[0]=expo[0];
			k.coef[0]=coef[0];
			k.expo[1]=ob.expo[0];
			k.coef[1]=ob.coef[0];
		
	}
	return k;
		
	}
	void display()
	{
		cout<<coef[0]<<"x"<<expo[0]<<"+"<<coef[1]<<expo[1];
		
	}
};
main()
{
	poly ob1(2,4),ob2(3,4),ob3(0,0);
	ob3=ob1+ob2;
	ob3.display();	
}
