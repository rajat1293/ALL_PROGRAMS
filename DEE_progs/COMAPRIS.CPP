#include<iostream.h>
#include<conio.h>
class comp{
int num;
public:
comp():num(0){}
comp(int no):num(no){}
void operator>=(comp c2);
void get_data()
{
cin>>num;
}
};

void comp::operator>=(comp c2)
{
if(num>=c2.num)
cout<<"true"<<endl;
else
cout<<"false"<<endl;
}


void main()
{
comp c1(20);
comp c2;
clrscr();
cout<<"enter the number"<<endl;
c2.get_data();
c1>=c2;
getch();
}

