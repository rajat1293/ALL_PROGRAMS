//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
class abc{
	int a;
	public:
		abc(int q=0):a(q)
		{
			cout<<"const"<<a<<endl;
		}
		~abc()
		{
			cout<<"dest"<<a<<endl;
		}
		void func(){
			abc ob(4);
		}
};
int main()
{
	abc ob(3);
	ob.func();
}

