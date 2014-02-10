#include<iostream>
#include<stdio.h>
#include<process.h>
using namespace std;
int leapyear(int yy)
{
	if(yy%400==0||(yy%100!=0&&yy%4==0))
	return 1;
	return 0;	
}
enum Month{jan=1,feb,march,april,may,june,july,august,sept,octo,nov,decem
		};
		class Date
{
		private:
	int d,y;
	 Month m;
	static Date default_date;
	public:
		Date(int dd=0,Month mm=Month(0),int yyyy=0) 
		{
			if (yyyy==0) yyyy=default_date.y;
			if(mm==0) mm= default_date.m;
			if(dd==0) dd=default_date.d;
		int max;
		switch(mm){
			case feb:
				max=28+leapyear(yyyy);
				break;
				case april:case june:case sept: case nov:
					max=30;
					break;
					case jan: case march:case may: case july: case august: case octo: case decem:
						max=31;
						break;
						default:
							cout<<"bad date\n";
							exit(2);
		}
		if(dd<1||dd>max){
			cout<<"bad date\n";
							exit(4);
		}
		y=yyyy;
		m=mm;
		d=dd;
}
void operator ++ ()
{
    d=d+1;
	Month b=m;
	int c=y;
	int max;
	switch(m){
			case feb:
				max=28+leapyear(y);
				break;
				case april:case june:case sept: case nov:
					max=30;
					break;
					case jan: case march:case may: case july: case august: case octo: case decem:
						max=31;
						break;}
	if(d>max)
	{d=1;
		m=Month((m+1));
		if(m==Month(13))
		m=jan;
		y+=1;
		}
		}

	//return Date(dd,b,c);	
void disp()
{cout<<"the new date is";
	cout<<d<<'/'<<m<<'/'<<y<<endl;
	
}
void operator -- ()
{

   d=d-1;
	Month b=m;
	int c=y;
	int max;
		if(d<1)
{
			m=Month(m-1);
		switch(m){
			case feb:
				max=28+leapyear(c);
				break;
				case april:case june:case sept: case nov:
					max=30;
					break;
					case jan: case march :case may: case july: case august: case octo: case decem:
						max=31;
						default:
							m=Month(12);
							max=31;
}
d=max;
if(m==decem)
{y=y-1;
}
//	return Date(dd,b,c);
}
}};
Date Date::default_date(12,Month(4),1993);
int main()
{
	int a,c;
	int b;
	char  e,d;
cout<<"enter 2 dates in form dd/mm/yyyy"<<endl;
cout<<"enter date 1"<<endl;
cin>>a>>d>>b>>e>>c;
Date ra(a,Month(b),c);
cout<<"enter date 2"<<"\n";
fflush(stdin);
cin>>a>>d>>b>>e>>c;
Date ra1(a,Month(b),c); 
while(1){
	cout<<"enter 1 to increment date 1\n"
<<"enter 2 to increment date 2\n"
<<"enter 3 to decrement date 1\n"
<<"enter 4 to decrement date 2\n"
<<"enter 5 to display both dates\n"
<<"enter any other to quit\n";	
cin>>a;
switch(a){
case 1: ++ra;
ra.disp();
break;
case 2: 
++ra1;
ra1.disp();
break;
case 3:
	--ra;
	ra.disp();
	break;
	case 4:
		--ra1;
		ra1.disp();
       break;
       case 5:
       	ra.disp();
       	ra1.disp();
       	break;
		default:
			exit(6);
}
}
return 0;
}









