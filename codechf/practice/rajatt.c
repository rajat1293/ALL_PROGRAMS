#include<stdio.h>
#define MAX 100
char Survey(int x,int y)
{
printf("S %d %d\n", x, y);
fflush(stdout);
char res;
scanf(" %c", &res);
return res;
}
void Neutralize(int x, int y)
{ printf("N %d %d\n", x, y);
fflush(stdout); /* but it is not necessary here */
}
int main()
{ int n,m,k;
int RAJAT[MAX][MAX]= {0};
scanf("%d%d%d",&n,&m,&k);
int count=0; int i=0,j=0;
char res; int c;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(!(RAJAT[i][j]))
{
res=Survey(i,j);
if (res=='M')
{
count++;
Neutralize(i,j);
RAJAT[i][j]=1;
}
else if (res=='0')
{
if(i>=0&&j+1>=0&&i<n&&j+1<n) RAJAT[i][j+1]=1;
if(i+1>=0&&j>=0&&i+1<n&&j<n) RAJAT[i+1][j]=1;
if(i+1>=0&&j+1>=0&&i+1<n&&j+1<n) RAJAT[i+1][j+1]=1; }
else if(res=='3')
{
if(i>=0&&j+1>=0&&i<n&&j+1<n&&!RAJAT[i][j+1]) {
count++;
RAJAT[i][j+1]=1;
Neutralize(i,j+1);
}
if(i+1>=0&&j>=0&&i +1<n&&j<n&& !RAJAT[i+1][j]) {
count++;
RAJAT[i+1][j]=1;
Neutralize(i+1,j);
}
if(i+1>=0&&j+1>=0&&i+1<n&&j+1<n&& !RAJAT[i+1][j+1])
{
count++;
RAJAT[i+1][j+1]=1;
Neutralize(i+1,j+1);
}
}
else
{
if(i>=0&&j +1>=0&&i<n&&j+1<n&&!RAJAT[i][j+1]) { RAJAT[i] [j+1]=1;
res=Survey(i,j +1);
if(res=='M') {count++; Neutralize(i,j+1);
RAJAT[i][j+1]=1;
}
}
if(i+1>=0&&j>=0&&i+1<n&&j<n&&!RAJAT[i+1][j]) {
RAJAT[i+1][j]=1;
res=Survey(i+1,j);
if (res=='M') {count++;
RAJAT[i+1][j]=1;
Neutralize(i+1,j);}
}
if(i+1>=0&&j+1>=0&&i+1<n&&j+1<n&&!RAJAT[i+1][j+1]) {
RAJAT[i+1][j +1]=1;
res=Survey(i+1,j+1);
if(res=='M')
{ count++;
RAJAT[i+1][j+1]=1;
Neutralize(i+1,j+1);}
}
}
}
if(count==m) {
printf("Done");
break; }
}
if(count==m) break;
}
return 0;
}

