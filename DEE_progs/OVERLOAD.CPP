/* to Overload the '+','-','*','/' operations and performing these operations on two complex no.s */

# include<iostream.h>
# include<conio.h>

class over
{
 float real;
 float img;
 public:
 over():real(0),img(0)
 {}
 over(float x,float y):real(x),img(y)
 {}
 void display()
 {
 char op;
 if(img>0)
 op='+';
 else
 {
 op='-';
 img=-1*img;
 }
 cout<<real<<op<<"i"<<img<<endl;
 }
 over operator+(over);
 over operator-(over);
 over operator*(over);
 over operator/(over);
};
 over over::operator+(over p)
 {
  p.real=real+p.real;
  p.img=img+p.img;
  return(p);
  }
 over over::operator-(over p)
 {
  p.real=real-p.real;
  p.img=img-p.img;
  return(p);
  }
 over over::operator*(over p)
 {
  int x=p.real;
  p.real=real*p.real-img*p.img;
  p.img=real*p.img+img*x;
  return(p);
  }
 over over::operator/(over p)
 {
  over x=p;
  p.real=real*p.real+img*p.img;
  p.img=real*p.img-img*x.real;
  x.real=x.real*x.real;
  x.img=x.img*x.img;
  x.real=x.real+x.img;
  p.real=p.real/x.real;
  p.img=p.img/x.real;
  return(p);

    }

void main()
{
 clrscr();
 int x,y;
 over o3;
 cout<<"enter the real and imaginary parts";
 cin>>x>>y;
 over o1(x,y);
 cout<<"enter the second complax no.";
 cin>>x>>y;
 over o2(x,y);
 cout<<"sum of no. is";
 o3=o1+o2;
 o3.display();
 cout<<"difference of no. is";
 o3=o1-o2;
 o3.display();
 cout<<"product of no. is";
 o3=o1*o2;
 o3.display();
 cout<<"division of no. is";
 o3=o1/o2;
 o3.display();
 getch();
 }