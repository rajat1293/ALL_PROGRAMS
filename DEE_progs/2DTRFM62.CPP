#include<iostream>
//#include<conio.h>
#include<graphics>
#include<math.h>
using namespace std;
struct matrix
{
float a[20][20];
};
void matmul(matrix &,matrix&,int,int,int&,int);
void drawpoly(matrix,int);
void main()
{
int gd=DETECT,gm,n;
initgraph(&gd,&gm,"C:\\tc\\bgi");
matrix p,tr,sc,rot;
for(int i=0;i<3;i++)
 {
 for(int j=0;j<3;j++)
  {
  tr.a[i][j]=i==j?1:0;
  sc.a[i][j]=i==j?1:0;
  rot.a[i][j]=i==j?1:0;
  }
 }
cout<<"Enter no of sides in polygon.";
cin>>n;
cleardevice();
cout<<"Enter coordinates of polygon in a cycle(either clockwise or anticlockwise)";
for(i=0;i<n;i++) //CMO
 {
 cin>>p.a[0][i]>>p.a[1][i];
 p.a[2][i]=1;
 }
drawpoly(p,n);
cout<<"Enter what u want to do?\n1-translate\n2-rotate\n3-resize.\nelse-Exit";
int choice;
cin>>choice;
int c=3;
switch(choice)
{
case 1:
cout<<"Enter new origin";
cin>>tr.a[0][2]>>tr.a[1][2];
matmul(tr,p,3,3,c,n);
break;
case 3:
cout<<"Enter scaling factors";
cin>>sc.a[0][0]>>sc.a[1][1];
matmul(sc,p,3,3,c,n);
break;
case 2:
cout<<"Enter angle of rotation(in degrees).";
float deg,rad,cosine,sine;
cin>>deg;
rad=3.14*deg/180.0;
cosine=cos(rad);
sine=sin(rad);
rot.a[0][0]=cosine;
rot.a[0][1]=-sine;
rot.a[1][0]=sine;
rot.a[1][1]=cosine;
matmul(rot,p,3,3,c,n);
break;
}
cleardevice();
/*for(i=0;i<3;i++)
 {
 for(int j=0;j<n;j++)
  {
  cout<<p.a[i][j]<<"\t";
  }
 cout<<endl;
 }*/
drawpoly(p,n);
getch();
}

void matmul(matrix &y,matrix &z,int m,int n,int &p,int q)
{
matrix r;
for(int i=0;i<m;i++)
 {
 for(int j=0;j<q;j++)
  {
  int sum=0;
  for(int k=0;k<n;k++)
   {
   sum+=y.a[i][k]*z.a[k][j];
   }
  r.a[i][j]=sum;
  }
 }
p=m;
z=r;
}

void drawpoly(matrix p,int n)
{
for(int i=0;i<n;i++)
{
line(p.a[0][i],p.a[1][i],p.a[0][(i+1)%n],p.a[1][(i+1)%n]);
}
}
