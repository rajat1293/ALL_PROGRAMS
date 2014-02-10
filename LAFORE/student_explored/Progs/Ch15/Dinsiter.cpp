// dinsiter.cpp
// demonstrates insert iterators with queues
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
   {
   int arr1[] = { 1, 3, 5, 7, 9 };  //initialize d1
   int arr2[] = {2, 4, 6};          //initialize d2
   deque<int> d1;
   deque<int> d2,d3,d4;

   for(int i=0; i<5; i++)           //transfer arrays to deques
      d1.push_back( arr1[i] );
   for(int j=0; j<3; j++)
      d2.push_back( arr2[j] );
      for(int j=0; j<3; j++)
      d3.push_back( arr2[j] ); 
	  for(int j=0; j<3; j++)
      d4.push_back( arr2[j] );                            //copy d1 to back of d2
   copy( d1.begin(), d1.end(), back_inserter(d2) );
   cout<<"\nd2: ";
   for(int k=0; k<d2.size(); k++)
      cout << d2[k] << ' ';
   cout << endl;
   copy( d1.begin(), d1.end(), front_inserter(d3) );
   cout << "\nd3: ";                //display d2
   for(int k=0; k<d3.size(); k++)
      cout << d3[k] << ' ';
   cout << endl;
   cout<<"\nd4: ";
   copy( d1.begin(), d1.end(), inserter(d4,d4.begin()) );
   for(int k=0; k<d4.size(); k++)
      cout << d4[k] << ' ';
   
   return 0;
   }
//ther are three kinds of insert operations 
//inserter
//back_inserter
//front_inserter
//here back_inserter we see that d2 is the taarget so the elements of d1 are insrted at the back of d2
//like pushback function
//A D3 WHICH IS CREATED IN THIS FRONT INSERTIN TAKE PLACE AND SO THE EMENTS ARE INSRTD IN REVERSE ORDER
//in d4 the inserter is used and the ements are inserted in proper order as it uses the insert function
