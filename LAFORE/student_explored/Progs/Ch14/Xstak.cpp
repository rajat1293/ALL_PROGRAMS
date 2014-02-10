// xstak.cpp
// demonstrates exceptions
#include <iostream>
using namespace std;
const int MAX = 3;              //stack holds 3 ints
////////////////////////////////////////////////////////////////
class Stack
   {
   private:
      int st[MAX];              //stack: array of integers
      int top;                  //index of top of stack
   public:
      class Range               //exception class for Stack
         {  
		 public:
		 Range(){
		 	cout<<"Crange\n";
		 }
		 ~Range() {
		 	cout<<"desrange\n";
		 }                    //note: empty class body
         };
         ~Stack(){
         	cout<<"desstack";
         }
//--------------------------------------------------------------
      Stack()                   //constructor
	      { top = -1; 
		  cout<<"cstack";}
//--------------------------------------------------------------
      void push(int var)
	      {
         if(top >= MAX-1)       //if stack full,
            throw Range();      //throw exception
         st[++top] = var;       //put number on stack
         }
//--------------------------------------------------------------
      int pop()
	      {
         if(top < 0)            //if stack empty,
            throw Range();      //throw exception
         return st[top--];      //take number off stack
         }
   };
////////////////////////////////////////////////////////////////
int main()
   {
   Stack s1;

   try
      {
      s1.push(11);
      s1.push(22);
      s1.push(33);
//    s1.push(44);                        //oops: stack full
      cout << "1: " << s1.pop() << endl;
      cout << "2: " << s1.pop() << endl;
      cout << "3: " << s1.pop() << endl;
      cout << "4: " << s1.pop() << endl;  //oops: stack empty
      }
   catch(Stack::Range)                    //exception handler
      {
      cout << "Exception: Stack Full or Empty" << endl;
      }
   cout << "Arrive here after catch (or normal exit)" << endl;
   return 0;
   }
//1.stack 2.range 3.exception 4.des 5.des.6.arrve7.desstack
//the above order is when the clss objct is created outside the try box...
//if it is created inside the try box the destructoor of the stck clss would have beeen 
//done before the catch block gets executed...
//see example Xsyntax.cpp
//CONSTRUCOR IS CLALLED ONCE BUT THE DESTRUCTOR IS CALLED TWICE
//which CONSTRUCTOR THE ONE OF THAT OF DEFALUT OR WHITCH ONE)
