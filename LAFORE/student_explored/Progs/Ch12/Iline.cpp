// iline.cpp
// file input with strings
#include <fstream>                  //for file functions
#include <iostream>
using namespace std;

int main()
   {
   const int MAX = 8;              //size of buffer
   char buffer[MAX];                //character buffer
   ifstream infile("TEST.TXT");
      //create file for input
 if( !infile.eof() )           //until end-of-file
      {
      infile.getline(buffer,26,',');  //read a line of text
      cout << buffer << endl;       //display it
      }
      if( !infile.eof() )  //or can do infile.good()         //until end-of-file
      {
      infile.get(buffer,20);  //read a line of text
      cout << buffer << endl;       //display it
      }
   return 0;
   }
   //without the max we are not getting line printed...??
   //check..??
   //use getline its safer...
   // 	IMP CONCLUSIONS FROM THEOUGH INVESTIGATION OF THE GET COMMAND :
   	//1.THE format(get,delim) and get(str) are not supported and when we use the
   	//form get(str,delim) we actually get the ascii value of delim wahich is used as a MAX
   	// and the delim is the third arguent which if not presentt '\n' is taken by default
   	//SO the first line is getting printed by 2 values form of GET()....
   	//a character less the MAX specified is printed ...
   	//CANT READ THE NEXT LINE AS \N REMAINS IN THE STD INPUT
