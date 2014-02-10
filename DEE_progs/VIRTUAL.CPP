#include<iostream.h>
#include<conio.h>
class abst{
public:
virtual float area(float ,float ){return(0);}
};
class derived1:public abst{
public:
float area(float a,float b)
{
return(.5*a*b);
}
};

class derived2:public abst{
public:
float area(float a,float b){
return(a*b); }
};

void main()
{
derived1 d1;
derived2 d2;
float c;
clrscr();
abst *ptr;
ptr=&d1;
c=ptr->area(2.2,4);
cout<<"area of triangle is"<<c;
ptr=&d2;
cout<<"area of rectangle is"<<ptr->area(2,4)<<endl;
getch();
}
