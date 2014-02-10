#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 10000003
#define MOL 109546051211ULL

unsigned long long factorial[SIZE];

int main()
{
    unsigned long long n,r,i;
    memset(factorial, 0, sizeof(factorial));
    cin>>n;
    factorial[1]=1;
    factorial[2]=2;
    for (i=3; i<=n; i++) 
    {
        factorial[i]=(factorial[i-1]*i)%MOL;
    }
    r=1;
    for (i=1; i<=n; i++) 
    {
        r=(factorial[i]*r)%MOL;
    }
    cout<<r<<endl;
}
