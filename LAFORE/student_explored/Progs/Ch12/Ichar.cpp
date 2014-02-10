// ichar.cpp
// file input with characters
#include <fstream>                //for file functions
#include <iostream>
using namespace std;

int main()
   {
   char ch;                       //character to read
   ifstream infile("TEST.TXT");   //create file for input
   while( infile )                //read until EOF or error
      {
     ch= infile.get();  
// infile.get(ch); 
 //if(infile.eof())          //read character
   //  break;
	  cout << ch;
	                   //display it
      }
   cout << endl;
   return 0;
   }
   //two zz at the end due to reason mentioned in self programs
   //this format one z,othr one zz
   //checking in between 
