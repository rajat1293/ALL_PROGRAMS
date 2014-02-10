// vector.cpp
// demonstrates push_back(), operator[], size()
#include <iostream>
#include <vector>
using namespace std;

int main()
	{
	vector<char> v(100);                 // create a vector of ints

	v.push_back(10);               // put values at end of array
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
   v[-1]=122;
	v[0] = 20;                     // replace with new values
	v[3] = 23;
   cout <<v.max_size();
	for(int j=0; j<v.size(); j++)  // display vector contents
		cout << " "<<v[j] << ' ';        // 20 11 12 23
   cout << endl;
   return 0;
	}
//maxsize returns the no of ements which can be printed
//size returns thee no of elemnts int the container
