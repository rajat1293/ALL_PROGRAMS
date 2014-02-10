#include<iostream>
#include<conio.h>
using namespace std;//san
class beta
{
      class alpha
{
      public:
      void display()
      {
           cout<<"display of alpha executed\n";
      }
};
           alpha a;
           public:
           void show()
      {
           cout<<"show of beta executed\n";
           a.display();
      }
};
      main()
{
      beta bb;
      bb.show();
      getch();
      return 0;
}
