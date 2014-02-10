#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct res{
	int ind;
	int x,y;
	int pep;
	 bool soli[102];
bool operator () (const res & r ,const res & s){
	return r.pep> s.pep;
}

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
bool sol[102];
int main(){
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
	cout<<endl;
	for(int i=1;i<=m;i++){
		r[i].pep=0;
		for(int j=1;j<=nn;j++){
			if(distance(r[i],s[j],n))
		{
				r[i].ind=i;
				r[i].pep += s[j].pep;	
				r[i].soli[i]= true;
//				cout<<j<<" "<<r[i].pep<<" "<<i<<" " <<r[i].x<<" "<<r[i].y<<endl;
		}
	}
	}
	cout<<endl;
	cout<<endl;
	sort(r+1,r+m+1,res());
	for(int i=1;i<=m;i++)
	cout<<r[i].x<<" "<<r[i].y<<" "<<r[i].pep<< " "<<endl;
	cout<<endl;
	
/*for(int i=1 ;i<= k;i++){
	for(int j=1;j<=m;j++)
	{
		cout<<j<<" "<<i<<" "<<s[j].pep;
			cout<<endl;
	}

}
*/	
	
	for(int i=1;i<=k;i++){
		for(int j=1;j<=nn;j++){
			if(r[r[i].ind].soli[j]==true){
			if(sol[j]==true);
			else
			{
				countt += s[j].pep;
				sol[j]=true;
			//	cout<<j<< " ";
				
			}
}
}
//cout<<i<<" ";
cout<<endl;
}
	printf("%d\n",countt);
}
