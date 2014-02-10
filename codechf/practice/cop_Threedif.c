#include<stdio.h>
#define MOD 1000000007
int main(){
int t;
scanf("%d",&t);
long long a,b,c,temp,ans;
while(t--){
scanf("%lld%lld%lld",&a,&b,&c);
if(a>b){
temp=a;
a=b;
b=temp;
}
if(b>c){
temp=b;
b=c;
c=temp;
}
if(a>b){
temp=a;
a=b;
b=temp;
}
ans=((((a%MOD)*((b-1)%MOD))%MOD)*((c-2)%MOD))%MOD;
 
printf("%lld\n",ans);
}
//getch();
return 0;
}
