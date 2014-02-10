/* overloading ++,--,>=,<= operators by printing numbers between two numbers*/

# include<iostream.h>
# include<conio.h>

class over
{
 int a;
 public:
 over():a(0)
 {}
 over(int x):a(x)
 {}
 over operator++();
 over operator--();
 int operator>=(over);
 int operator<=(over);
 void display()
 {
  cout<<a;
  }
};
over over::operator++()
{
 return(a++);
}
over over::operator--()
{
 return(a--);
 }
int over::operator>=(over p)
{
 if(a>=p.a)
 return(1);
 else
 return(0);
}
int over::operator<=(over p)
{
 if(a<=p.a)
 return(1);
 else
 return(0);
}

void main()
{
 clrscr();
 int x;
 cout<<"enter the number";
 cin>>x;
 over op(x);
 cout<<"enter the number";
 cin>>x;
 cout<<endl;
 over op2(x);
 for(;op<=op2;++op)
 op.display();
 op--;
 cout<<endl;
 for(;op>=op2;--op)
 op.display();
 getch();
}