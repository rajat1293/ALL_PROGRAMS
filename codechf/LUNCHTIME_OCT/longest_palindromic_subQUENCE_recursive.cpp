#include<stdio.h>
#include<string.h>
 //WE MAINTAIN HERE TWO BASE CASES AS THE STRING CAN BE OF EVEN AS WELL AS OF 
 //ODD LENGTH SO THE CASES HAVE TO HANDLED SEPARATELY IN EACH CASE
//THIS IS A BASIC RECURSIVE SOLUTION 
 /////------------
// A utility function to get max of two integers
int max (int x, int y) { return (x > y)? x : y; }
 
// Returns the length of the longest palindromic subsequence in seq
int lps(char *seq, int i, int j)
{
   // Base Case 1: If there is only 1 character
   if (i == j)
     return 1;
 
   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;
 
   // If the first and last characters match
   if (seq[i] == seq[j])
      return lps (seq, i+1, j-1) + 2;
 
   // If the first and last characters do not match
   return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}
 
/* Driver program to test above functions */
int main()
{
    char seq[] = "GEEKSFORGEEKS";
    int n = strlen(seq);
    printf ("The length of the LPS is %d", lps(seq, 0, n-1));
    getchar();
    return 0;
}
