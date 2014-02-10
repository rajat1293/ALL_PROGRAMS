Program To Concatenate 2 Strings

# include<iostream.h>
# include<conio.h>
# include<string.h>
# include<stdio.h>

class concat
{
 char str[30];
 public:
 void getdata()
 {
  cout<<"enter a string:- ";
  gets(str);
 }
 void putdata()
 {
  cout<<"string is:-"<<endl<<endl;
  puts(str);
 }
 concat operator+(concat);
};

concat concat::operator+(concat c)
{
 strcat(c.str,str);
 return(c);
}
void main()
{
 clrscr();
 concat c1,c2,c3;
 c1.getdata();
 c2.getdata();
 c3=c2+c1;
 c3.putdata();
 getch();
}