//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
class Learn
{
int x, y;
public:
void Programming(int &xx, int &yy)
{
x = xx++;
y = yy;
cout<< xx << " " << yy;
}
};
int main()
{
int x = 10;
int &y = x;
Learn obj;
obj.Programming(x , y);
return 0;
}



