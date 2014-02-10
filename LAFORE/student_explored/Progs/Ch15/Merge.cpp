// merge.cpp
// merges two containers into a third
#include <iostream>
#include <algorithm>          //for merge()
using namespace std;

int src1[] = { 2, 3, 4, 6, 8 };
int src2[] = { 1, 3, 5 };
int dest[8];

int main()
   {                          //merge src1 and src2 into dest
   merge(src2, src2+3,src1, src1+5,  dest);
   for(int j=0; j<8; j++)     // display dest
      cout << dest[j] << ' ';
   cout << endl;
   return 0;
   }
   //the order of the source1 and source2 does not effect the output as the outout is always sorted in
   //the dest container
