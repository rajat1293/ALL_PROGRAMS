#include<stdio.h>
long int fib[1000001];
int main(){
int i;
fib[0]=1;
fib[1]=2;
for(i=2;i<999999;i++){
fib[i]=fib[i-1]+fib[i-2];
fib[i]%=MOD;
}}
//AMORTISED STORING FIBONACCI SEQUENCE IN AN ARRAY

