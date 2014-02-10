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
		class Date
{
		private:
	int d,y;
	 int m;
	static Date default_date;
	public:
		Date(int dd=0,int mm=0,int yyyy=0) 
		{
			if (yyyy==0) yyyy=default_date.y;
			if(mm==0) mm= default_date.m;
			if(dd==0) dd=default_date.d;
		int max;
		switch(mm){
			case 2:
				max=28+leapyear(yyyy);
				break;
				case 4:case 6:case 9: case 11:
					max=30;
					break;
					case 1: case 3: case 5: case 7: case 8: case 10: case 12:
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
Date operator ++ ()
{
int dd=d+1;
	int b=m;
	int c=y;
	int max;
		switch(b){
			case 2:
				max=28+leapyear(c);
				break;
				case 4:case 6:case 9: case 11:
					max=30;
					break;
					case 1: case 3: case 5: case 7: case 8: case 10: case 12:
						max=31;
						break;
						default:
							cout<<"bad date\n";
							exit(3);
		}
		if(dd<1||dd>max){
			cout<<"bad date\n";
							exit(3);
		}
	return Date(dd,b,c);	
}
Date operator -- ()
{
int dd=d-1;
	int b=m;
	int c=y;
	int max;
		switch(b){
			case 2:
				max=28+leapyear(c);
				break;
				case 4:case 6:case 9: case 11:
					max=30;
					break;
						case 1: case 3: case 5: case 7: case 8: case 10: case 12:
					max=31;
						break;
						default:
							cout<<"bad date\n";
							exit(3);
		}
		if(dd<1||dd>max){
			cout<<"bad date\n";
							exit(3);
		}
	return Date(dd,b,c);

}};
Date Date::default_date(12,4,1993);
int main()
{
	int a,c;
	int b;
	char  e,d;
cout<<"enter 2 dates in form dd/mm/yyyy"<<endl;
cout<<"enter date 1"<<endl;
cin>>a>>d>>b>>e>>c;
Date ra(a,b,c);
cout<<"enter date 2"<<"\n";
fflush(stdin);
cin>>a>>d>>b>>e>>c;
Date ra1(a,b,c);	
}











