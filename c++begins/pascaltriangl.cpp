#include<iostream>
using namespace std;
#include<conio.h>
double factorial(double n)
{ if (n==0)
return 1;
else
return n*factorial(n-1);
}
 main()
{ //clrscr();
double i,j,n,x;
cout<<"Enter the Number of Rows to be displayed : ";
cin>>n;
cout<<endl<<endl;
for(i=0;i<n;i++)
for(j=0;j<=i;j++)
{ x=factorial(i)/(factorial(j)*factorial(i-j));
gotoxy(40-2*i+4*j,2*i+5);
cout<<x;
}
cout<<endl;
//getch();
}
//see in borland c++
