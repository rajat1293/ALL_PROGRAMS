#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define MAX 10000000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));


void sieve()
{
    int i,j;
    isprime[0]=0xA28A28AC;
    for(int i=1;i<=MAX/32+1;i+=3)
    {
            isprime[i]  =0x28A28A28;
            isprime[i+1]=0x8A28A28A;
            isprime[i+2]=0xA28A28A2;
    }
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }
}

int main()
{
    sieve();
    int n;
    cin>>n;
    
    vector<int> counts(10000000);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        counts[a]++;        
    }
    
	vector<int> primecounts(10000005);
    for(int i=2;i<=10000000;i++)
    {
        if(isSet(i))
        {
            for(int j=i;j<=10000000;j+=i)
            {
                primecounts[i]+=counts[j];
            }
        }
    }
    
    for(int i=1;i<=10000000;i++)
    	primecounts[i]+=primecounts[i-1];
    int q;
    cin>>q;
    while(q--)
    {
        int li,ri;
        cin>>li>>ri;
        li=max(2,li);
        if(li>10000000)
            cout<<0<<endl;
        else
        {
            ri=min(10000000,ri);
            cout<<primecounts[ri]-primecounts[li-1]<<endl;
        }
    }
    
}
