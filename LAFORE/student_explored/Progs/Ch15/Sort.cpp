// sort.cpp
// sorts an array of integers
#include <iostream>
#include <algorithm>
using namespace std;
                               // array of numbers
int arr[] = {45, 2, 22, -17, 0, -30, 25, 55};

int main()
   {
   sort(arr, arr+8);           // sort the numbers

   for(int j=0; j<8; j++)      // display sorted array
      cout << arr[j] << ' ';
   cout << endl;
   return 0;
   }

//adding ,greater<int>()at the end of the sort function sorts in decreasing order
//while adding less<int>() sorts ot in increasing order,but it is  redundant as bt defaukt it is sorted 
// in increasing order
