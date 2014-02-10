#include<iostream.h>
#include<conio.h>
class time{
int hrs;
int min;
public:
time():hrs(0),min(0){}
time(int hours,int minutes):hrs(hours),min(minutes){}
void operator+(time);
void get_time()
{
cin>>hrs>>min;
}
};

void time::operator+(time t2)
{
int x;
hrs=hrs+t2.hrs;
min=min+t2.min;
if(min>=60)
 {
 min=min%60;
 x=hrs/60;
 hrs=hrs+x;
 }
cout<<"the time is"<<hrs<<":"<<min<<endl;
}

void main()
{
time t1(10,20);
time t2 ;
clrscr();
cout<<"enter the time t2"<<endl;
t2.get_time();
t1+t2;
getch();
}


