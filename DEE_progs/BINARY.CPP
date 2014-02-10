#include<iostream.h>
#include<conio.h>
class binaryop{
float op;
public:
binaryop():op(0){}
binaryop(int oper):op(oper){}
binaryop operator+(binaryop );
binaryop operator-(binaryop);
binaryop operator*(binaryop);
binaryop operator/(binaryop);
void display()
{
cout<<"the result of the operation is"<<op<<endl;
}
};

binaryop binaryop::operator+(binaryop op2)
{
return(op+op2.op);
}

binaryop binaryop::operator-(binaryop op2)
{
return(op-op2.op);
}

binaryop binaryop::operator*(binaryop op2)
{
return(op * op2.op);
}

binaryop binaryop::operator/(binaryop op2)
{
return(op/op2.op);
}

void main()
{
binaryop op1(10);
binaryop op2(20);
binaryop op3;
binaryop op4;
binaryop op5;
binaryop op6;
clrscr();
op3=op1+op2;
op3.display();
op4=op1-op2;
op4.display();
op5=op1*op2;
op5.display();
op6=op1/op2;
op6.display();
getch();
}



