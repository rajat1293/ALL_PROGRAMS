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
};
void counter::operator++()
{
++count;
}

void main()
{
counter c1,c2,c3;
clrscr();
c1.get_count();
c2.get_count();
++c1;
++c2;
++c2;
++c2;
cout<< "the value of count 1 is ="<<c1.get_count()<<endl;
cout<< "the value of count 2 is ="<<c2.get_count()<<endl;
getch();
}