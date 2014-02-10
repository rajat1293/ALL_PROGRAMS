#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct res{
	int x,y;
	int pep;

};
struct soli{
	int x,y,pep;
};
inline bool distance(res r,soli s,int n){
	if(((s.x-r.x)*(s.x-r.x)+(r.y-s.y)*(r.y-s.y))<=n*n){
		return true;
	}
	return false;
} 
int main()
{
	int m1=0,m2=m1,m3=m1;
	int countt = 0;
	res r[12];
	soli s[102];
	int k,n;
	scanf("%d%d",&k,&n);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	scanf("%d%d",&r[i].x,&r[i].y);
	int nn;
	scanf("%d",&nn);
	for(int i=1;i<=nn;i++)
	{
		scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].pep);
	}
	for(int i=0;i<poww(2,m);i++){
		for(int j=0;i<nn;j++){
			
		}
	}	
	
	
	
}
