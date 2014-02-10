#include<iostream.h>
#include<conio.h>
class distance{
int feet;
int inch;
public:
distance():feet(0),inch(0){}
distance(int ft,int in):feet(ft),inch(in){}
void operator+(distance);
void get_dis()
{
cin>>feet>>inch;
}
};

void distance::operator+(distance d2)
{
int x;
feet=feet+d2.feet;
inch=inch+d2.inch;
if(inch>=12)
 {
 inch=inch%12;
 x=feet/12;
 feet=feet+x;
 }
cout<<"the distace is"<<feet<<" feet "<<inch<<" inches "<<endl;
}

void main()
{
distance d1(10,20);
distance d2 ;
clrscr();
cout<<"enter the distance d2"<<endl;
d2.get_dis();
d1+d2;
getch();
}


