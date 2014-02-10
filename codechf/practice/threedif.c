#include<stdio.h>
#define MOD 1000000007
void  qrsort( long long a[],int p,int r)
{
int q ;
if(p<r)
  {

   q = patti(a,p,r);
   qrsort(a,p,q-1);
   qrsort(a,q+1,r);}
}
int patti( long long a[],int p,int r)
{
     long long x,t,k;
    int  i,j;
    x=a[r];
    i=p-1;
    for(j=p;j<r;j++)
        {
        if(a[j]<=x)
        {
            i=i+1;
            t=a[i];
            a[i]=a[j];
            a[j]=t;        
        }
    }
            k=a[i+1];
            a[i+1]=a[r];
            a[r]=k;
            return (i+1);

}
int main()
{
     long long  a[3];
	int p,r,i,t;
	 long long k;
	scanf("%d",&t);
	while(t--){
    for (i=0;i<3;i++)
        scanf("%lld",&a[i]);
    qrsort(a,0,2);
     k=((((a[0]%MOD)*((a[1]-1)%MOD))%MOD)*((a[2]-2)%MOD))%MOD;
printf("%lld\n",k);
}
return 0;}
