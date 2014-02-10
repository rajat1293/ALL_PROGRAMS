#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
int P[100010];
char s[100010][5];
int aa[100010];
int sum[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%s%d",s[i],&aa[i]);
        P[0]=0;
        sum[0]=0;
        for (int i=1;i<=n;i++)
            sum[i]=sum[i-1]+aa[i];
        LL ans=0;
        int a=0;
        for (int i=1; i<=n; i++)
        {
            if(2*a-i>=0 && P[2*a-i] < 2*a-i-(a-P[a]))P[i] = P[2*a-i];
            else
            {
                int st = 2*a-i-(a-P[a])+1;
                int ed = min(i, n-i);
                int j = st;
                for(; j <= ed; j++)
                    if(s[i-j][0] != s[i+j][0]||aa[i-j]!=aa[i+j])break;
                P[i] = j-1;
            }
            if(P[i]+i > a)a = i;
            int x=P[i]+1;
            ans+=(sum[i+x-1]-sum[i-x]+1)/2;
            int ll=i-x,rr=i+x;
            if (ll>=1&&rr<=n&&s[ll][0]==s[rr][0])
            {
                ans+=min(aa[ll],aa[rr]);
            }
            ans+=((long long)aa[i]*(aa[i]+1))/2;
            ans-=(aa[i]+1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

