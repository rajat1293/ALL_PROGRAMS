// ferrors.cpp
// checks for errors opening file
#include <fstream>          // for file functions
#include <iostream>
using namespace std;

int main()
   {
   ifstream file;
   file.open("a:edata.dat");

   if( !file )
      cout << "\nCan't open GROUP.DAT";
   else
      cout << "\nFile opened successfully.";
   cout << "\nfile = " << file;
   cout << "\nError state = " << file.rdstate();
   cout << "\ngood() = " << file.good();
   cout << "\neof() = " << file.eof();
   cout << "\nfail() = " << file.fail();
   cout << "\nbad() = " << file.bad() << endl;
   file.close();
   return 0;
   }
   //rdstate is set to 1 if file cant be opened ,its error state is 4
   //good returns true if no bits are set
   //at end of file ,eof bit =1
   //
