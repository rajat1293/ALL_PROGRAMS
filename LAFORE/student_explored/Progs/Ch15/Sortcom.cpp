// sortcom.cpp
// sorts array of strings with user-written comparison function
#include <iostream>
#include <string>                       // for strcmp()
#include <algorithm>
#include<cstring>
using namespace std;                                        // array of string
bool alpha_comp(char*, char*);          // declaration

int main()
    {
   char * names[] = { "George", "Penny", "Estelle",
                  "Don", "Mike", "Bob" };
   sort(names, names+6, alpha_comp);    // sort the strings

   for(int j=0; j<6; j++)               // display sorted strings
      cout << names[j] << endl;
   return 0;
   }

bool alpha_comp(char* s1, char* s2)     // returns true if s1<s2
   {
   return ( strcmp(s1, s2)<0 ) ? true : false;
   }
  
 //we can use the in buit functions of the string class gretter<> and less<>
