#include<iostream.h>
#include<conio.h>
class counter{
int count;
public:
counter():count(0){}
int get_count()
{
return count;}
void operator++();
void operator--();
int operator-();
};
void counter::operator++()
{
++count;
}
void counter::operator--()
{
--count;
}
int counter::operator-()
{
int temp;
temp=-count;
return(temp);
}
void main()
{
counter c1,c2,c3;
clrscr();
c1.get_count();
c2.get_count();
++c1;
cout<<"the value of count 1 is ="<<c1.get_count()<<endl;
++c1;
cout<<"the value of count 1 is="<<c1.get_count()<<endl;
++c2;
++c2;
++c2;
--c1;
cout<<"the value of count 2 is="<<c2.get_count()<<endl;
--c2;
cout<< "the value of count 1 is ="<<c1.get_count()<<endl;
cout<< "the value of count 2 is ="<<c2.get_count()<<endl;
cout<<"the value of count 1 and count 2 after negation is"<<-c1 <<"and"<< -c2  <<endl;
getch();
}