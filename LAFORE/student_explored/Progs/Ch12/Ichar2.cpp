// ichar2.cpp
// file input with characters
#include <fstream>                //for file functions
#include <iostream>
using namespace std;

int main()
   {
   ifstream infile("TEST.TXT");   //create file for input

   cout << infile.rdbuf();        //send its buffer to cout
   cout << endl;
   return 0;
   }
   //this function returns a pointer to the streambuff object associated with 
   //the stream object ,this contains a buffer that holds the cahracters rread from the stream
