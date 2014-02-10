#include<iostream.h>
#include<conio.h>
template<class T>
class stack{
T a[4];
int top;
public:
stack():top(-1){}
void push(T);
T pop();
};
template <class T>
void stack <T>::push(T b)
{
if(top>2)
cout<<"overflow"<<endl;
else
a[++top]=b;
}
template <class T>
T stack<T>::pop()
{
T temp;
if(top<0)
cout<<"underflow"<<endl;
else
{
temp=a[top];
top--;
 }return(temp);
}
void main()
{
stack <int> c1;
int temp;
char ch;
clrscr();
cout<<"do u want 2 enter"<<endl;
cin>>ch;
while(ch=='y')
{
cout<<"enter the element"<<endl;
cin>>temp;
c1.push(temp);
cout<<"wnat 2 cont"<<endl;
cin>>ch;
}
cout<<"popped element"<<c1.pop()<<endl;
getch();
}

