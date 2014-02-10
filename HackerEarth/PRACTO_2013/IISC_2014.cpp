#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int maxi[200]={0};
//IT WAS THE LIS SUM CHAINHING PROBLEM
 //maximum chain length of pairs
// Structure for a pair
//USE LIS WHICH YOU MADE WITH THE ELEMENTS OF THE UNSORTED PART IT THE FINISHING
//THIS IS A SLIGHT VARIATION OF THE ACTIVITY SELECTION PROBLEM AND CAN BE SOLVED IN nLOGN TIME 
struct ppair
{
  int a;
  int b;
};
 
// This function assumes that arr[] is sorted in increasing order
// according the first (or smaller) values in pairs.
int maxChainLength(  ppair arr[], int n)
{
   int i, j, max = 0;
   int *mcl = (int*) malloc ( sizeof( int ) * n );
   /* Initialize MCL (max chain length) values for all indexes */
   for ( i = 0; i < n; i++ )
    {
      mcl[i] = 1;
      maxi[i]=arr[i].b-arr[i].a;
	}
   /* Compute optimized chain length values in bottom up manner */
   for ( i = 1; i < n; i++ )
 {
    int alpha=0;
	  for ( j = 0; j < i; j++ )
    {
         if ( arr[i].a > arr[j].b && alpha<maxi[j]  )		           
		   {
		    alpha=maxi[j];
		   }
 	}
 		maxi[i]=alpha+maxi[i];
 }  // mcl[i] now stores the maximum chain length ending with pair i
 
   /* Pick maximum of all MCL values */
   for ( i = 0; i < n; i++ )
      cout<< maxi[i]<<" ";
	  if ( max < maxi[i] )
         max = maxi[i];
 
   /* Free memory to avoid memory leak */
   free( mcl );
 
   return max;
}
 
/* Driver program to test above function */
int main()
{
    struct ppair arr[] = { {5, 24}, {15, 25},
                          {27, 40}, {50, 60} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of maximum size chain is %d\n",
           maxChainLength( arr, n ));
    return 0;
}
