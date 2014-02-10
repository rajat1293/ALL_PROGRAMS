#include<iostream>
using namespace std;
#include<stdlib.h>
#include<stdio.h>
class date 
{private:
	int d,m,y;
public:
	date()
	{
		d=1;m=1;y=2001;
		
	}
date(int a,int b,int c)
{
	d=a;m=b;y=c;
	
}
date (char st[])
{
	sscanf(st,"%d/%d/%d",&d,&m,&y);
}
void display()
{
    cout<<d<<"/"<<m<<"/"<<y<<endl;
}

};
main()
{
	int a,b,c,d,e,f;
	char i,st[22];
    cout<< "enter the date as dd/mm/yy\n";
    cin>>a>>i>>b>>i>>c;
	date t1(a,b,c);
	t1.display();
	cout<<"enter the date as mm/dd/yy\n";
    cin>>d>>i>>e>>i>>f;
	date t2(d,e,f);
	t2.display();
	cout<<"enter the date as d/m/year\n";
	cin>>st;
	date t3(st);
	t3.display();
	
}
	
