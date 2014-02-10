
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<string.h>
#define tr(c,it) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define itor(c) typeof(c.begin())
#define ll long long
#define vi vector<int>
#define vs vector<string>
#define si set<int>
#define msi multiset<int>
#define ii pair<int,int>
#define sii set<ii>
#define vii vector<ii>
#define vvi vector<vi>
#define pb push_back
#define mp make_pair

using namespace std;

#define num 10000001
bool arr[num]={false};
int p[num]={0},sz=0;
ll cnt[num]={0};

int main()
{
    ios::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t=0,i=0,j=0,n=0,k=0,temp=0,m,l,r;
    cin>>n;
    //string str;
    //int arr[100002]={0};   
    for(i=0;i<n;++i)
    {
        cin>>j;
        p[j]++;
    }
    // taking the input through the array starting at index 0 to less than n
    // and incrementing the value of the corresponding index for each number 
    int sqrtnum=sqrt(num);
//-------------------------------------------------------------------------------------
    for(i=2;i<=sqrtnum;++i)
    {
        if(arr[i]==false)
        {
            //k=2*i;
            if(p[i])
            {
                cnt[i]+=p[i];// ADDING TO COUNT AS THE NUMBER WILL BE DIVISIBLE BY ITSELF
                				// AND THEN DOING IT ZERO AS IT IS USED 
                p[i]=0;
            }
            for(j=i*i;j<num;j+=i)
            {
                arr[j]=true; // IN SEIVE THE NON PRIMES ARE DONE TRUE BY THE PRIMES i 
                if(p[j]) // IF THE NON PRIME INDEX IS HAVING A COUNT 
                {
                    temp=j; // ASSINGING THE VALUE TO TEMP
                    while(temp%i==0) // DIVIDING THE NUMBER BY THE PRIME UNTIL IT GETS DIVIDED
                        temp/=i;
                    p[temp]+=p[j]; //THEN INCREMENTING THE COUNT OF TEMP AS THE NUMBER 
                    // IS NOW CONVERTED INTO THE TEMP THING
                    cnt[i]+=p[j]; // THEN INCREMENTING THE COUNT OF THE PRIME AS IT IS DIVISIBLE
                    // BY IT NOW IT WILL SURELY BE DIVISIBLE AS IT IS IN ITS SEIVE ....
                    p[j]=0;// DOING IT ZERO AS IT CAN REPEAT ....
                }
            }
        }
    }
    // creating seive  and incrementing the count of the numbers divisible by that prime.......
//---------------------------printing seive--------------------------------------
//for(int i=2;i<100;i++)
	//if(arr[i]==false){
	//	cout<<cnt[i]<<" ";
//	}
	
//just printing upto 100 ...
//---------------------------------------------------------------------
    for(i=3;i<num;++i)
    {
        if(p[i] && (!arr[i]))
            cnt[i]+=p[i];
        cnt[i]+=cnt[i-1];
    }
//----------------------------
// againg printing it to get it done 
//cout<<endl;
//for(int i=2;i<100;i++)
//		cout<<cnt[i]<<" ";
//  NOW THE COUNT HOLDS THE NUMBER ELEMENTS THAT HAVE THE THING IN TOTAL....
// I MEAN TO SAY THAT 
//----------------------------
    cin>>m;
    for(i=0;i<m;++i)
    {
        cin>>l>>r;
        if(l>=num){
            cout<<"0\n";
            continue;
        }
        if(r>=num)
            r=num-1;
        cout<<cnt[r]-cnt[l-1]<<endl;
    }
    return 0;
}
