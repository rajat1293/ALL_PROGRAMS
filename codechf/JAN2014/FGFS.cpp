#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define gc getchar_unlocked
int countt=0;
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
//-----------------------
struct pep{
	int s;
	int f;
	int p;
bool operator () (const pep & a,const pep & b){
	return a.p < b.p ? true : false ;
}
};
//---------------------------
void select(pep human[], int i,int n)
{
    countt++;
    int k=i;
        //   cout<<human[k].s<< " "<< human[k].f<<endl;
    for (int j = i+1; j < n; j++)
    {
      if (human[j].s>= human[k].f)
      {
      //    cout<<human[j].s<< " "<< human[j].f<<endl;
		  countt++;
       k = j;
      }
    }
}
//---------------------------
struct sortt{
	
bool operator () (const pep & a,const pep & b){
	return a.f < b.f ? true : false ;
}
	
	
};
int main()
{
	int t;
	cin>>t;
	while(t--){
		countt=0;
		int n,k;
		int initial = 0;
		//cin>>n>>k;
		scanint(n);
		scanint(k);
		pep human[n+2];
		for(int i=1;i<=n;i++){
		//	cin>>human[i].s>>human[i].f>>human[i].p;	
		scanint(human[i].s);
		scanint(human[i].f);
		scanint(human[i].p);
		}
		sort(human+1,human+n+1,pep());
		//for(int i=1;i<=n;i++)
		//	cout<<human[i].s<<" "<< human[i].f<<" "<< human[i].p<<endl;
		for(int i=1;i<=n; ){
			initial=0;
			initial++;
			for(int j=i+1;j<=n;j++){
				if( human[j].p == human[i].p ){
					initial++;
				}
				else 
				 break;
			}
			if(initial>1)
			{
				sort(human+i,human+i+initial,sortt());
				select(human,i,initial+i);
		//		for(int k=i;k<initial+i;k++)
		//		  cout<<human[k].s <<" "<< human[k].f <<" "<< human[k].p <<endl;
			}
			else 
				countt++;
			i+=initial;
		}		
		printf("%d\n",countt);
	}
}
