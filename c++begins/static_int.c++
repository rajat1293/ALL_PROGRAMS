#include<iostream>
using namespace std;
#include<conio.h>
class myclass
{
      private:
              static int c;//sanjivniiiii
      public:
              myclass();
              ~myclass();
              static void display();
};
myclass::myclass()
{
                  c=c+1;
                  
}
int myclass::c;
myclass::~myclass()
{
                   cout<<"\nobject destroyed";
}
void myclass:: display()
{
	cout<<"\nrrr"<<c;
}
int main()
{
    myclass m1,m2,m3;
    myclass ::display();
    }
