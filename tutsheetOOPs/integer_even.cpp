#include<iostream>
using namespace std;
#include<conio.h>
class number
{
  private :
          int integer;
          public:
         int  iseven()
         {
            if(integer%2==0)
            return 0;
            else return 1;            
            }
            number(int a)
            {
                    integer=a;
            }
  int factorial()
      {
          int k=1;
           int i;
           for(i=1;i<=integer;i++)
           {
                            k=k*i;
                            }
                            return k;
                            }};
main()
{int num;
      cout<<"enter the number";
      cin >> num;
      number n(num);
      cout<<"the factorial is"<<n.factorial();
      if(n.iseven()==0)
      cout <<"\nEVEN";
      else cout <<"\nODD";
      getch();
      }
      
      
      
      
      
      
                                  
                            
                                                    
