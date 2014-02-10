#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int main()
{
int n,i=0,ans=0;
int val=0;
int n1,n2;
char op;
cin>>n;
for(i=0;i<n;i++)
{
   scanf("%d%c%d",&n1,&op,&n2);
   // cin >> n1 >> op >> n2;
   if(n2==2)
   n1 *= 2;
   val += n1;
}
   val = ceil(val/4);
   printf("%d\n",val+1);
}
