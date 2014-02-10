#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxN = 100000;

int n;
char s[maxN+1];
int d[maxN];

void calc_d()
{
	int l=0,r=-1;
	for(int i=0;i<n;i++)
	{
		int k=0;
		if(i<=r)
			k=min(d[l+r-i+1],r-i+1);
		for(;i+k<n && i-k-1>=0 && s[i+k]==s[i-k-1];k++);
		d[i]=k;
		if(r<i+k-1) l=i-k,r=i+k-1;
	}
}

pair<int,int> d_ind[maxN];

int a[maxN+1];

void add(int x,int d)
{
	for(;x<=n;x+=x&-x) a[x]+=d;
}

int sum(int x)
{
	int s=0;
	for(;x>0;x-=x&-x) s+=a[x];
	return s;
}

LL calc_res()
{
	int i;
	for(i=0;i<n;i++)
		d_ind[i]=make_pair(2*i-d[i],i+1);
	sort(d_ind,d_ind+n);
	memset(a,0,4*(n+1));
	int k=0;
	LL ans=0;
	for(i=0;i<n;i++)
	{
		for(;k<n && d_ind[k].first<=2*i;k++)
			add(d_ind[k].second,1);
		add(i+1,-1);
		int j=i+d[i];
		if(3*j>n+2*i) j=(n+2*i)/3;
		ans+=sum(j+1);
	}
	return ans;
}

LL beauty()
{
	n=strlen(s);
	calc_d();
	return calc_res();
}

int main()
{
	int TST;
	scanf("%d\n",&TST);
	for(int tst=0;tst<TST;tst++)
	{
		gets(s);
		LL ans=beauty();
		printf("%lld\n",ans);
	}
	return 0;
}
