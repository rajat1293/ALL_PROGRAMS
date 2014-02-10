#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>
#define pi 3.14
void cond(float [3][3]);
float x[3][3],y[3][3];
void mult(float [3][3],float [3][3]);
void mult1(float [3][3]);
void copy(float [3][3]);
void mult2(float [3][3]);
void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 int i,j,k,d=1;
 float f[3][3],r[3][3],x,y,f1[3][3],f2[3][3],f3[3][3],t[3][3],rt[3][3],r2[3][3];
 f[0][0]=200;f[1][0]=200;f[2][0]=1;
 f[0][1]=225;f[1][1]=250;f[2][1]=1;
 f[0][2]=175;f[1][2]=250;f[2][2]=1;
 setcolor(YELLOW);
 for(i=0;i<2;i++)
   line(f[0][i],f[1][i],f[0][i+1],f[1][i+1]);
 line(f[0][0],f[1][0],f[0][2],f[1][2]);
 for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
    {
     if(i==j)
      {
       r[i][j]=1;
       t[i][j]=1;
       rt[i][j]=1;
       r2[i][j]=1;
      }
     else
      {
       r[i][j]=0;
       r2[i][j]=0;
       t[i][j]=0;
       rt[i][j]=0;
      }
    }
  }
 r[0][0]=0;
 r[0][1]=1;
 r[1][0]=-1;
 r[1][1]=0;
 t[0][2]=-200;
 t[1][2]=-200;
 rt[0][2]=200;
 rt[1][2]=200;
 r2[0][0]=cos(pi/30);
 r2[0][1]=-sin(pi/30);
 r2[1][0]=sin(pi/30);
 r2[1][1]=cos(pi/30);
 mult(f,t);
 mult1(r);
 mult2(rt);
 copy(f1);
 mult(f1,t);
 mult1(r);
 mult2(rt);
 copy(f2);
 mult(f2,t);
 mult1(r);
 mult2(rt);
 copy(f3);
 cond(f1);
 for(i=0;i<2;i++)
  line(f1[0][i],f1[1][i],f1[0][i+1],f1[1][i+1]);
 line(f1[0][0],f1[1][0],f1[0][2],f1[1][2]);
 cond(f2);
 for(i=0;i<2;i++)
   line(f2[0][i],f2[1][i],f2[0][i+1],f2[1][i+1]);
 line(f2[0][0],f2[1][0],f2[0][2],f2[1][2]);
 cond(f3);
 for(i=0;i<2;i++)
  line(f3[0][i],f3[1][i],f3[0][i+1],f3[1][i+1]);
 line(f3[0][0],f3[1][0],f3[0][2],f3[1][2]);
 getch();
 while(d)
  {
   delay(25);
   cleardevice();
   line(200,200,200,400);
   mult(f,t);
  mult1(r2);
  mult2(rt);
  copy(f);
  mult(f1,t);
  mult1(r2);
  mult2(rt);
  copy(f1);
  mult(f2,t);
  mult1(r2);
  mult2(rt);
  copy(f2);
  mult(f3,t);
  mult1(r2);
  mult2(rt);
  copy(f3);
  cond(f);
  for(i=0;i<2;i++)
   line(f[0][i],f[1][i],f[0][i+1],f[1][i+1]);
  line(f[0][0],f[1][0],f[0][2],f[1][2]);
  cond(f1);
  for(i=0;i<2;i++)
   line(f1[0][i],f1[1][i],f1[0][i+1],f1[1][i+1]);
  line(f1[0][0],f1[1][0],f1[0][2],f1[1][2]);
  cond(f2);
  for(i=0;i<2;i++)
   line(f2[0][i],f2[1][i],f2[0][i+1],f2[1][i+1]);
  line(f2[0][0],f2[1][0],f2[0][2],f2[1][2]);
  cond(f3);
  for(i=0;i<2;i++)
   line(f3[0][i],f3[1][i],f3[0][i+1],f3[1][i+1]);
  line(f3[0][0],f3[1][0],f3[0][2],f3[1][2]);
 }

 getch();
}
void cond(float a[3][3])
{
 int i,j;
 for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
     {
      if(a[i][j]<0)
       a[i][j]*=(-1);
     }
  }
}
void mult(float a[3][3],float t[3][3])
{
 int i,j,k;
 for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
    {
     x[i][j]=0;
     for(k=0;k<3;k++)
      {
       x[i][j]+=t[i][k]*a[k][j];
      }
    }
  }

}
void mult1(float r[3][3])
{
 int i,j,k;
 for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
    {
     y[i][j]=0;
     for(k=0;k<3;k++)
      {
       y[i][j]+=r[i][k]*x[k][j];
      }
    }
  }
}
void mult2(float t[3][3])
{
 int i,j,k;
 for(i=0;i<3;i++)
  {
   for(j=0;j<3;j++)
    {
     x[i][j]=0;
     for(k=0;k<3;k++)
      {
       x[i][j]+=t[i][k]*y[k][j];
      }
    }
  }

}
void copy(float q[3][3])
{
 for(int i=0;i<3;i++)
  {
  for(int j=0;j<3;j++)
   {
    q[i][j]=x[i][j];
   }
 }
}