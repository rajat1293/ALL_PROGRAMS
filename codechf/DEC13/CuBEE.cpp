//AUTHOR Rajat Gambhir
//time 7 pm 15/12/13
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<utility>
#include<map>
#include<string>
#include<cstring>
#include<set>
#include<list>
#include<iterator>
#include<iostream>
#include<cmath>
#define gc getchar
using namespace std;
//-----------fast input------------
void scanint(int &x)
{
	register int c=gc();
	x=0;
	int neg=0;
	for(;((c<48||c>57)&&c!='-');c=gc());
	if(c=='-')
	{
		neg=1;c=gc();
	}
	for(;c>47&&c<58;c=gc())
	{
		x=(x<<1)+(x<<3)+c-48;
	}
		if(neg)
		x=-x;
	}
//----------------------------------
	long long poww(int n,int m) 
{ 
  	if(m==0) return (1);
   	long long x=poww (n,m/2);
    if(m%2==0) return (x*x); 
	else return (((x*x))*n) ;
}
//---------------------------------
int CU[42][42][42]={0};
void find(int n,int pp){
	int countt;
	int rajat;
	int mennu;
	float p=(float)pp/100.0;
	
	int dynamic[42][42][42]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dynamic[i][j][k]=dynamic[i-1][j][k]+dynamic[i][j-1][k]+dynamic[i][j][k-1]-(dynamic[i-1][j-1][k]+dynamic[i][j-1][k-1]+dynamic[i-1][j][k-1])+dynamic[i-1][j-1][k-1];
				dynamic[i][j][k]+=CU[i][j][k];			
			}
		}
	}
	
	
	for(rajat=n;rajat>=1;rajat--){
		countt=0;
		float m=(float)rajat;
		mennu=(ceil)((m*m*m)*p);
		for(int i=rajat;i<=n;i++){
			for(int j=rajat;j<=n;j++){
				for(int k=rajat;k<=n;k++){
					int x=dynamic[i][j][k]-(dynamic[i-rajat][j][k]+dynamic[i][j-rajat][k]+dynamic[i][j][k-rajat]) +(dynamic[i-rajat][j-rajat][k]+dynamic[i][j-rajat][k-rajat]+dynamic[i-rajat][j][k-rajat])-dynamic[i-rajat][j-rajat][k-rajat];
					if(x>=mennu)
					countt++;	
				}
			}
		}
		if(countt)
		break;
	}
	
	 if(rajat!=0)
	 cout<<rajat<<" "<<countt<<endl;
	 else
	 cout<<"-1"<<endl;
}



int main(){
	int t;
	scanint(t);
	while(t--){
		int n,p;
		scanint(n);
		scanint(p);
		char c1[n+1][n+1][n+1];
		char c2[n+1][n+1][n+1];
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					(c1[i][j][k])=gc();
				}
			}
		}
		gc();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					c2[i][j][k] =gc();
				}
			}
		}
		gc();
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(c1[i][j][k]==c2[i][j][k])
					CU[i][j][k]=1;
					else
					CU[i][j][k]=0;
				}
			}
		}
		
		find(n,p);
	}
}
