#include<iostream>
#include<conio.h>
using namespace std;
template<class T,class Z>
class demo{
T a;
Z b;
public:
demo():a(0),b(0){}
demo(T x,Z y):a(x),b(y){}
void sum();

};
template <class T,class Z>
void demo<T,Z>::sum()
{ cout<<"the result is"<<(a+b);}
main()
{
//clrscr();
demo <int,float> d1(10,20.5);
d1.sum();
//getch();
}
