#include<iostream>
using namespace std;
#include<stdlib.h>
#define size 5
void fff();//the scope of the class is only in that function...
main()
{
	
	fff();
}	

void fff(){
			class stack
{
       private:
		int arr[size],roll,top;
		public:
			stack(int a)
			{
				top=-1;
			roll=a;
			cout << "\nrrr\n"<<roll;
			}
			~stack()
			{
				
				cout<<endl <<roll<<endl;
			}
		
			int push(int element)
			{
			if(top==size-1)
			cout<<"stack full\n";
			else 
			arr[++top]=element;
		}};
stack stk(100);
stk.push(5);


}
