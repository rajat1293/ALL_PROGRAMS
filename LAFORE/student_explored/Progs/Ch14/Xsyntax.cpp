// xsyntax.cpp
// not a working program
////////////////////////////////////////////////////////////////i
#include<iostream>
using namespace std;
class AClass                     // a class
   {
   public:
   class AnError                 // exception class
      {
	  int b;
	  public:
      	AnError(){
      		b=0;
      		cout<<"anerror\n";
      	}
      	//AnError(int a){
      	//	b=a;
      	//	cout<<"int \n";
      //	}
      	AnError(const AnError& ob){
      		b=ob.b;
      		cout<<"copy constructor\n";
      	}
      	
      AnError operator ++(int){
      //	return AnError(b+1);
      }
      	~AnError(){
      			cout<<b;
      		cout<<"desanerror\n";
      	}
      };
      AClass(){
      	cout<<"aclass\n";
      }
      ~AClass(){
      
      	cout<<"desaclassssss\n";
      }
   void Func(int a)                   // a member function
      {//AnError s();
      if( a==0)
         throw AnError()  ;    // throw exception
      }
   };
////////////////////////////////////////////////////////////////
int main()                       // application
   {
   try                           // try block
      {
      AClass obj1; 
	  int a;
	  cout<<"enter a number";
	  cin>>a;	                // interact with AClass objects
      obj1.Func(a);               // may cause error
      }
   catch(AClass::AnError ob)        // exception handler
      {
	  cout<<"catch\n";                          // (catch block)
      }
       cout << "Arrive here after catch (or normal exit)" << endl;
  
   return 0;
   }
   //two times desructor for error class
   //object of AClass destoryed before the running of catch block
   //this is a compicated rather interesting case
   //THE CONCLUSIONS OR RATHER OBSERVATIONS FROM THIS CASE AARE:
   	//1.FIRST OF ALL WHEN WE CREATE AN OBJECT IN THE TRY BLOCK WE SEE THAT THE OBJECY OF ACLASS
   	//IS DESTRUCTED AS SOON AS THE TRY BLOCK GETS OVER
   	//2.(VERY IMP)TO CREATE  A COPY OF A TEMPORARY OBJECT WE NEED A CONSTANT IN COOPY CONSTUCTOR
   	//FIRST A COPY IS CREATED THROUGH A SIMPLE CONSTUCTOR ...
   	//AND WHEN THE OBJECT IS PASSED IN CATCH BLOCK THE TEMPORARY OBJECT IS GETTING COPIED..
   	//SO WE  NEED A CONST ...
   	// TWO DESTRUCTORS ARE RUNNING IN THIS CASE FIRST FOR THE COPY CONSTRUCTOR ONE 
   	// AND THEN FOR THE TEMPORARY OBJECT..
   	// 3.WHEN A SIMPLE OBJECT IS PASSED AS AN OBJECT NO SIMPLE COPY (S) TAKES PLACE...
   	//(27.4.2013)AN EXEPTION THROWN FROM A CONSTRUCTOR 
   	//RUNS WITHOUT ANY DESTRUCTOR
