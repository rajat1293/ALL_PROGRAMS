Program to overload >,<,==<!= operators nd perform these operations on distance variables,where distance
is class having two variables feet and inches

# include<iostream.h>
# include<conio.h>

class distance
{
 int feet;
 int inches;
 public:
 distance():feet(0),inches(0)
 {}
 distance(int f,int i):feet(f),inches(i)
 {}
 void display()
 {
  cout<<"feet= "<<feet<<" inches= "<<inches;
 }
  int operator >(distance);
  int operator <(distance);
  int operator ==(distance);
  int operator !=(distance);
};
int distance::operator >(distance d)
{
 if(d.feet>feet)
  return(0);
 else if(feet>d.feet)
  return(1);
 else if(d.inches>inches)
  return (0);
 else if(d.inches<inches)
  return(1);
 else
  return(0);
}
int distance::operator <(distance d)
{
 if(d.feet>feet)
  return(1);
 else if(feet>d.feet)
  return(0);
 else if(d.inches>inches)
  return (1);
 else if(d.inches<inches)
  return(0);
 else
  return(1);
}
int distance::operator ==(distance d)
{
 if(d.feet==feet && d.inches==inches)
  return(1);
 else
  return(0);
}
int distance::operator !=(distance d)
{
 if(d.feet==feet && d.inches==inches)
  return(0);
 else
  return(1);
}

void main()
{
  clrscr();
  int x,y;
  cout<<"enter the first distance in feet and inches(<=11)";
  cin>>x>>y;
  distance d1(x,y);
  cout<<"enter the second distance in feet and inches(<=11)";
  cin>>x>>y;
  distance d2(x,y);
  cout<<"enter the third distance in feet and inches(<=11)";
  cin>>x>>y;
  distance d3(x,y);

  /* Compairing d1&d2, use of overloaded <,> operators*/
  if(d1>d2)
  {
   cout<<endl<<"larger distance from first and second is";
   d1.display();
  }
  else if(d1<d2)
  {
   cout<<endl<<"larger distance from first and second is";
   d2.display();
  }
  else
   cout<<endl<<"first and second distance are equal";
  /* checking equality of first and third distance */
  if(d1==d3)
   cout<<endl<<"first and third distance are equal";
  else
   cout<<endl<<"first and third distance are not equal";
  /* checking inequality of second and third distance */
  if(d2!=d3)
    cout<<endl<<"second and third distance are not equal";
  else
    cout<<endl<<"second and third distance are equal";
  getch();
}