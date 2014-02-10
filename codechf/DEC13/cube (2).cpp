#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#define GETCHAR getchar
using namespace std;
inline int readInt()
{
int flag=1;
int n = 0;
char c;
while (1)
{
c=GETCHAR();
if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
}
return n;
}

int mycube[50][50][50]={0};
void solve(int n,int pp){
	float p=(float)pp/100.0;
	
	int dp[50][50][50]={0};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k]+dp[i][j][k-1]-(dp[i-1][j-1][k]+dp[i][j-1][k-1]+dp[i-1][j][k-1])+dp[i-1][j-1][k-1];
				dp[i][j][k]+=mycube[i][j][k];			
			}
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			cout<<dp[i][j][k]<<" ";
		}
	}*/
	int count;
	int l;
	int minimumones;
	
	for(l=n;l>=1;l--){
		count=0;
		float m=(float)l;
		minimumones=(ceil)((m*m*m)*p);
		for(int i=l;i<=n;i++){
			for(int j=l;j<=n;j++){
				for(int k=l;k<=n;k++){
					int x=dp[i][j][k]-(dp[i-l][j][k]+dp[i][j-l][k]+dp[i][j][k-l]) +(dp[i-l][j-l][k]+dp[i][j-l][k-l]+dp[i-l][j][k-l])-dp[i-l][j-l][k-l];
					if(x>=minimumones)
					count++;	
				}
			}
		}
		if(count)
		break;
	}
	
	 if(l!=0)
	 cout<<l<<" "<<count;
	 else
	 cout<<"-1";
	 cout<<"\n"; 
	
	
}



int main(){
	int t;
	t=readInt();
	while(t--){
		int n,p;
		n=readInt();
		p=readInt();
		char cube1[n+1][n+1][n+1];
		char cube2[n+1][n+1][n+1];
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					cube1[i][j][k]=GETCHAR();
					//cin>>cube1[i][j][k];
				}
			}
		}
		GETCHAR();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					cube2[i][j][k]=GETCHAR();
					//cin>>cube2[i][j][k];
				}
			}
		}
		GETCHAR();
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(cube1[i][j][k]==cube2[i][j][k])
					mycube[i][j][k]=1;
					else
					mycube[i][j][k]=0;
				}
			}
		}
		
		solve(n,p);
	}
	//getch();
}
