#include<iostrem.h>
#include<conio.h>
class cal{
int data;
public:
cal():cal(0){}
cal(int x):data(x){}
void sum()
{
data=data+data;}
void display()
{
cout<<"the result is"<<data<<endl;}
};
void main()
{
cal c1(5);
cal c2(10);
cal c3;
c3.sum(c1,c2);
c3.display();
getch();
}

