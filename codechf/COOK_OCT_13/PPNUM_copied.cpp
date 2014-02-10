#include<stdio.h>
#include<math.h>
#define max(i,j) i>j?i:j
int main()

{
int i,j,t; long long l,r,e[]={0,9,99,999,9999,99999,999999,9999999,99999999,999999999},s[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

scanf("%d",&t);
while(t--)
{
scanf("%lld%lld",&l,&r);
long long ld=(int)log10(l)+1;
long long rd=(int)log10(r)+1;
long long res=0ll;
while(ld!=rd){
res+= (long long) ( (l+e[ld])*(e[ld]-l+1ll) *  ld)/2ll;ld++;l=s[ld];
res %=1000000007ll;
}
res+= (long long) ((l+r)*(r-l+1)*ld)/2ll;
res %=1000000007ll;
printf("%lld\n",res);
}

return 0;
}
