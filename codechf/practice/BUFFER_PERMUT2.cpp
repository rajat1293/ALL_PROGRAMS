#include<iostream>
#include <cstdio>
 
using namespace std;
 
#define BUF 4096
 
char ibuf[BUF];
int ipt = BUF;
 
int readInt() {
while (ipt < BUF && ibuf[ipt] < '0') ipt++;
if (ipt == BUF) {
fread(ibuf, 1, BUF, stdin);
ipt = 0;
while (ipt < BUF && ibuf[ipt] < '0') ipt++;
}
int n = 0;
while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
if (ipt == BUF) {
fread(ibuf, 1, BUF, stdin);
ipt = 0;
while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
}
return n;
}
 
 
int main(){
int a[100001];
int n = readInt();
while(n>0){
bool flag=true;
for(int i=1;i<=n;i++)
a[i] = readInt();
for(int i=1;i<=n;i++){
if(a[a[i]]!=i){flag=false;break;}
}
if(flag)printf("ambiguous\n");
else printf("not ambiguous\n");
n=readInt();
}
 
return 0;
}
