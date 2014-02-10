#include<stdio.h>
//comlexty of this algo is log(n)
//-----
//SIMPLER ALGORITHM,,,,,,,,,

loat square(float x)
{
    float guess = 1;

    while(absolute(guess*guess - x) >= 0.0001 )
        guess = ((x/guess) + guess) / 2;

    return guess;
}
//-------
float squareRoot(float n)
{
  /*We are using n itself as initial approximation
   This can definitely be improved */
  float x = n;
  float y = 1;
  float e = 0.000001; /* e decides the accuracy level*/
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
 
/* Driver program to test above function*/
int main()
{
  int n = 50;
  scanf("%d",&n);
  printf ("Square root of %d is %f", n, squareRoot(n));
  getchar();
}
