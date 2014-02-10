#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
void main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\tc\\bgi");
int i,j,k;
float sx,sy,mx,my,hx,hy;
float rad=3.14/30.0;
//gettime
sx=250;
sy=201;
mx=250;
my=210;
hx=250;
hy=220;
while(1)
{
 for(j=0;j<12;j++)
  {
  for(k=0;k<60;k++)
   {
   delay(1000);
   cleardevice();
   circle(250,250,50);
   line(250,250,hx,hy);
   line(250,250,mx,my);
   line(250,250,sx,sy);
   sx-=250;
   sy-=250;
   float temp1=sx,temp2=sy;
   temp1=sx*cos(rad)-sy*sin(rad);
   temp2=sx*sin(rad)+sy*cos(rad);
   sx=temp1+250;
   sy=temp2+250;
   //if (abs(sx-250)
   }
  mx-=250;
   my-=250;
   float temp3=mx,temp4=my;
   temp3=mx*cos(rad)-my*sin(rad);
   temp4=mx*sin(rad)+my*cos(rad);
   mx=250+temp3;
   my=250+temp4;

  }
 hx-=250;
   hy-=250;
   float temp5=hx,temp6=hy;
   temp5=hx*cos(rad)-hy*sin(rad);
   temp6=hx*sin(rad)+hy*cos(rad);
   hx=250+temp5;
   hy=250+temp6;
}
}

/*void matmul(matrix)
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
} */

