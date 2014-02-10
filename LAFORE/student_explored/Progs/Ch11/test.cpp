//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
class alpha
   {
   private:
      int data,j;
       alpha(const alpha& a)            //copy constructor
         {
         data = a.data;
         cout << "\nCopy constructor invoked";
         }
   public:
      alpha()                    //no-arg constructor
         {
		 cout<<"no\n"; }
      alpha(int d,int ss)               //one-arg constructor
         { cout<<"yes"; }
     
         ~alpha(){
         	cout<<"\ndes\n";
         }
      alpha display()             //display
         { 
		 return alpha(4,9);//cout << data;
		  }
      void operator = (alpha& a) //overloaded = operator
         {
         //data = a.data;
         cout << "\nAssignment operator invoked";
         }
   };
   int main()
   {
   //	alpha k;
   //	alpha s;
   	//alpha k;
   	//s=k;
//  alpha l=alpha(8,9);
  alpha nn;
  nn.display();
  //alpha l(5,6);
   	
   }

