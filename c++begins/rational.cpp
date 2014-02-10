#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
		
}
int lcm(int a,int b)
{
	return a*b/gcd(a,b);	
}
class rational
{
	private:
		int num,deno;
		public:
			rational(int a,int b)
			{int i;
			if(a>b)
				i=gcd(a,b);
				else i=gcd(b,a);
				num=a/i;
				deno=b/i;
				
			}
			rational()
			{
				
				
			}
	rational operator + (rational obj)
	{
		
		rational aa;
		cout<<num<<endl<<obj.num<<endl;
		aa.deno=lcm(deno,obj.deno);
		aa.num=aa.deno/deno + aa.deno/obj.deno;
		cout<<aa.deno<<aa.num<<endl;
		return aa;
	}
	void display()
	{
		cout<<((float)num/deno);
		
		
	}
};
	main()
	{
		rational oj1(2,8),oj2(3,6),oj3;
		oj3=oj1+oj2; 
		oj3.display();
		
		
	}
		
		
		
		
	
	
	
	
	

