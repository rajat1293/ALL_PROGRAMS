// find_if.cpp
// searches array of strings for first name that matches "Don"
#include <iostream>
#include <string>        
#include <algorithm>
using namespace std;
//--------------------------------------------------------------
bool isDon(string name)      // returns true if name=="Don"
   {
   return name == "rajat";
   }
//--------------------------------------------------------------
string names[] = {"George","Estelle","Don","Mike","Bob","rajat"};

int main()
   {
   string* ptr;
    sort(names,names+6);
   for(int i=0;i<6;i++)
   cout<<names[i]<<endl;
   ptr = find_if( names, names+5, isDon );

   if(ptr==names+6)
      cout << "rajat is not on the list.\n";
   else
      cout << "rajat is element "
           << (ptr-names)
           << " on the list.\n";
   return 0;
   }
//it takes an extra parae=metr clled predicate which is a function object or a functin
//we can create our own function with this.
//THE SORTING OF THE STRINGS
