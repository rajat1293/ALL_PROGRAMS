#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
void main()
{
double xc=50;
int k=0,g=DETECT,di,ym,yc=50,r=7,y2;
initgraph(&g,&di,"c:\\tc\\bgi");
y2=yc;
ym=getmaxy();
while(k<50)
{
while(yc<ym-r)
{
circle(xc,yc,r);
yc++;
delay(2);
cleardevice();
}
while(yc>y2)
{
circle(xc,yc,r);
yc--;
xc+=0.3;
delay(6);
cleardevice();
}
}
getch();
}