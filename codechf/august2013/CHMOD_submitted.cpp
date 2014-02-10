#include<iostream> 
#include<stdio.h> 
#include<math.h>
 using namespace std;
long long poww(int n,int m,int MOD) 
{ 
  	if(m==0) return (1)%MOD;
   	long long x=poww (n,m/2,MOD);
    if(m%2==0) return (x*x)%MOD; 
	else return (((x*x)%MOD)*n) %MOD;
}

struct Number{ 
	  int num;
		int prime[ 102 ];
	    };
	    
	   int am[ 101 ][ 101 ]; 
	   Number numb[ 100006 ]; 
	   int main() 
	   { 
	   int j,t,l,r,m; 
	   int arr[30]; arr[1]=2; arr[2]=3; arr[3]=5; arr[4]=7; arr[5]=11; arr[6]=13; arr[7]=17; arr[8]=19; arr[9]=23; arr[10]=29; arr[11]=31; arr[12]=37; arr[13]=41; arr[14]=43; arr[15]=47; arr[16]=53; arr[17]=59; arr[18]=61; arr[19]=67; arr[20]=71; arr[21]=73; arr[22]=79; arr[23]=83; arr[24]=89; arr[25]=97;
	    int n,nn; 
		 scanf("%d",&n);
		 for(int i=1;i<= 100 ;i++) 
		 { if(i==2|| i==3||i==5||i==7|| i==11||i==13||i==17|| i==19||i==23||i==29|| i==31||i==37||i==41|| i==43||i==47||i==53|| i==59||i==61||i==67|| i==71||i==73||i==79|| i==83||i==89||i==97) am[i][i]=1; 
		 else { 
		 j=1;
		  nn=i;
		  while(nn>1) 
		  { 
		  if(nn%arr[j]==0) 
		  {
		   am[i][arr[j]]++;
		    nn=nn/arr[j]; 
			} else j++; 
			} 
			}
			 } 
		   for(int i=1;i<=n;i++) 
		  scanf("%d",&numb[i].num);
		   for(int i=1;i<=n;i++) { 
		   for(int k=1;k<=25;k ++) { 
		   numb[i].prime[arr [k]]=numb[i-1].prime [arr[k]];
		    numb[i].prime[arr [k]]+=am[numb[i].num] [arr[k]]; 
}
  }
 scanf("%d",&t);
  while(t--)
   {
    long long sum=1; 
  scanf("%d%d%d",&l,&r,&m);
   for(int i=1;i<=25;i++) { 
    sum=(sum*poww(arr [i],numb[r].prime[arr[i]]-numb[l-1].prime[arr [i]],m))%m;
	 } 
	 printf("%lld\n",sum%m);
	  } return 0;
	   }
