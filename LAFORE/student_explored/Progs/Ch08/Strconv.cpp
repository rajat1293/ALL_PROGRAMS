// strconv.cpp
// convert between ordinary strings and class String
#include <iostream>
using namespace std;
#include <string.h>             //for strcpy(), etc.
////////////////////////////////////////////////////////////////
class String                    //user-defined string type
   {
   private:
      enum { SZ = 80 };         //size of all String objects
      char str[SZ];             //holds a C-string
   public:
      String()                  //no-arg constructor
         { str[0] = '\0'; }
      String(const char s[] )        //1-arg constructor
         { strcpy(str, s); }    //   convert C-string to String
      void display() const      //display the String
         { cout << str; }
      operator char*()          //conversion operator
         { return str; }        //convert String to C-string
   };
////////////////////////////////////////////////////////////////
int main()
   {
   String s1;                   //use no-arg constructor
                                //create and initialize C-string
   char xstr[] = "Joyeux Noel! ";

   s1 = xstr;                   //use 1-arg constructor
                                //   to convert C-string to String
   s1.display();                //display String

   String s2 = "Bonne Annee!";  //uses 1-arg constructor
                                //to initialize String
   cout << static_cast<char*>(s2); //use conversion COUT<<S2 IS ACCEPTABLE
   //THOUGH THE TYPE CAST IS USED WE NEED NOT USE IT,IT WOULD BE 
   //LIKE USING ASSIGNENT OPERATOR...
   //COUT<<COULD BE IN SINGLE QOUTES for singl char
	cout << endl;	              //to convert String to C-string
	return 0;			           //before sending to << op
   }
   //ISSEUS
   //WHY S1 XSTR CALLS A CONSTRUCTOR ,WHY NOT THEN FOR DISTANCE ALSO....
   //35 WITHOUT THE CONVERSION ALSO IT WORKS
   //THE COMPLIER LOOKS FOR SOME CONVEERSON AS IT KNOWS NOTHG ABOUT HTE STRING CLASS
  // and fnds
