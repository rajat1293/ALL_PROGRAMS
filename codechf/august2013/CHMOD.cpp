#include<iostream>
#include<stdio.h>
#include<math.h>
#define MOD 1000000007  
using namespace std;
long long poww(int n,int m)
{
if(m==0) return 1;

long long x=poww(n,m/2);
if(m%2==0)
return (x*x)%MOD;
else
return (((x*x)%MOD)*n)%MOD;
}
struct Number{
	int num;
	int prime[102];
};
	Number numb[100002];
int main()
{
//	for(int i=1;i<=34;i++)
//	cout<<numb[0].prime[i];
	int j,t,l,r,m;
	int arr[30];
	arr[1]=2;
	arr[2]=3;
	arr[3]=5;
	arr[4]=7;
	arr[5]=11;
	arr[6]=13;
	arr[7]=17;
	arr[8]=19;
	arr[9]=23;
	arr[10]=29;
	arr[11]=31;
	arr[12]=37;
	arr[13]=41;
	arr[14]=43;
	arr[15]=47;
	arr[16]=53;
	arr[17]=59;
	arr[18]=61;
	arr[19]=67;
	arr[20]=71;
	arr[21]=73;
	arr[22]=79;
	arr[23]=83;
	arr[24]=89;
	arr[25]=97;
	int n,nn;
	cin>>n;
	for(int i=1;i<=n;i++)
	numb[0].prime[arr[i]]=0;
for(int i=1;i<=n;i++)
 cin>>numb[i].num;
 for(int i=1;i<=n;i++)
 {
 	for(int k=1;k<=25;k++)
	numb[i].prime[arr[k]]=numb[i-1].prime[arr[k]];		 
	 if(numb[i].num==2||numb[i].num==3||numb[i].num==5||numb[i].num==7||numb[i].num==11||numb[i].num==13||numb[i].num==17||numb[i].num==19||numb[i].num==23||numb[i].num==29||numb[i].num==31||numb[i].num==37||numb[i].num==41||numb[i].num==43||numb[i].num==47||numb[i].num==53||numb[i].num==59||numb[i].num==61||numb[i].num==67||numb[i].num==71||numb[i].num==73||numb[i].num==79||numb[i].num==83||numb[i].num==89||numb[i].num==97)
	 numb[i].prime[numb[i].num]++;
	 else 
	 { 
	 j=1;
	 nn=numb[i].num;
	 while(nn>1)
	 {
	 	if(nn%arr[j]==0)
	 	{
		numb[i].prime[arr[j]]++;
	    nn=nn/arr[j];
	}
	else 
	j++;
    }
}
//for(int k=1;k<=25;k++)
//	cout<< numb[i].prime[arr[k]]<<" "<<numb[i].num<<" "<<k<<" "<<arr[k]<<endl;
	
}
//cout<<n;
	 cin>>t;
  while(t--)
 {
 	long long sum=1;
   cin>>l>>r>>m;
 for(int i=1;i<=25;i++)
{
 //cout<<endl<<numb[l-1].prime[arr[i]]<<" "<<arr[i]<<endl;
 //cout<<endl<<numb[r].prime[arr[i]]<<" "<<endl; 
 sum=(sum*poww(arr[i],numb[l-1].prime[arr[i]]-numb[r].prime[arr[i]]))%MOD;
//cout<<sum<<endl;
}
 cout<<sum%m<<endl;
}
return 0;
}






