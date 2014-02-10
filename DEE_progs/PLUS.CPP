#include<iostream.h>
#include<conio.h>
class binaryop{
int op;
public:
binaryop():op(0){}
binaryop(int oper):op(oper){}
binaryop operator+(binaryop op);
};

binaryop binaryop::operator+(binaryop op)
{
binaryop op3;
op3.op=op+op2.op;
return(op3.op);
}

void main(){

binaryop op1(10);
binaryop op2(20);
clrscr();

cout<<"the sum is"<<(op1+op2).op<<endl;
getch();}


