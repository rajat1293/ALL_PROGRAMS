// vectcon.cpp
// demonstrates constructors, swap(), empty(), back(), pop_back()
#include <iostream>
#include <vector>
using namespace std;

int main()
	{                              // an array of doubles
	double arr[] = { 1.1, 2.2, 3.3, 4.4 };

	vector<double> v1(arr, arr+4); // initialize vector to array
	vector<double> v2(4);          // empty vector of size 4

   v2.swap(v1);                   // swap contents of v1 and v2

	while( !v2.empty() )           // until vector is empty,
		{
		cout << v2.back() << ' ';   // display the last element
      v2.pop_back();              // remove the last element
      }                           // output: 4.4 3.3 2.2 1.1
   cout << endl;
   return 0;
	}
//.back displays the last eleamt while .pop_back().pops the last elemat
//.two ways to initialize the vector and then 
//using swap we swap the contents of v1 and v2.
//v2.v1 or v1.v2 means virtually the same thing
//WE HAVE SWAP VERSION FOR ALGORITHM AS WELL..

