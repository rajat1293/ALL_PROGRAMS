#include<iostream>
#include<cstring>
using namespace std;
class roman
{
	private:
	char n[100];
	public:
		roman(char *a)
		{
			strcpy(n,a);
		}	
	int convert()
	{
		char *p,*d;
		d=n;
	int s=strlen(n);
	p=n+s-1;
		int num=0,flag=0;
		while(p>=d)
	{
		switch(*p)
		{
			case 'M':num+=1000;
			flag=1;
			break;
			case 'D':num+=500;
			flag=1;
			break;
			case 'C' : num+=100;
			flag=1;
			break;
			case 'L':num+=50;
			flag=1;
			break;
			case 'X':num+=10;
			flag=1;
			break;
			case 'V':num+=5;
			flag=1;
			break;
		    case 'I':if(flag)num-=1;
			else num+=1;	
		}
		p--;
		
	}
	return num;
	}	
};
class overload:public roman
{

	public:
		overload(char *a):roman(a)
		{
		}
int operator +(overload s)
	{
		int i = s.convert();
		int j= convert();
		return i+j;
	}	
	int operator -(overload s)
	{
		int i=convert();
		int j=s.convert();
		return i-j;
		
	}
	int operator *(overload s)
	{
		int i=convert();
		int j=s.convert();
		return i*j;
	}
	float operator /(overload s)
	{
		int i=convert();
		float j=s.convert();
		return i/j;
	}
int	operator ++ ()
	{
		int i=convert();
		i++;
		return i;
		
	}	
};

int main(){
	int num=0;
	char a[100];
	int k;
	cout<<"enter 2 numbers in romans ";
	cin>>a;
	overload raj1(a);
	cin>>a;
	overload raj2(a);
	cout<<"\nA+B "<<raj1+raj2;
	cout<<"\nA-B "<<raj1-raj2;
	cout<<"\nA*B "<<raj1*raj2;
	cout<<"\nA/B "<<raj1/raj2;
	cout<<"\n++A "<<++raj1;
	cout<<"\n++B "<<++raj2;
}
	
	
	
