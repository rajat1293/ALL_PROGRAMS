#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

    long long poww(int n,int m) 
{ 
  	if(m==0) return (1);
   	long long x=poww (n,m/2);
    if(m%2==0) return (x*x); 
	else return (((x*x))*n) ;
}
int main()
{

cout<<poww(2,46);
}
