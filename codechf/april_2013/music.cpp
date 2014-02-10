    #include<iostream>
    #include<cstdio>
    #include<map>
    using namespace std;
    long long B[100009];
    int sount;
    int patti(long long * L,int p,int r)
    {
    long long x,t;
    int i,j,k;
    x=L[r];
    i=p-1;
    for(j=p;j<r;j++)
    {
    if(L[j]<=x)
    {
    i=i+1;
    t=B[i];
    B[i]=B[j];
    B[j]=t;
    t=L[i];
    L[i]=L[j];
    L[j]=t;
    }
    }
    k=B[i+1];
    B[i+1]=B[r];
    B[r]=k;
    k=L[i+1];
    L[i+1]=L[r];
    L[r]=k;
    return (i+1);
     
    }
    void qrsort(long long *L,int p,int r)
    {
    int q ;
    if(p<r)
    {
     
    q = patti(L,p,r);
    qrsort(L,p,q-1);
    qrsort(L,q+1,r);}
    }
    int main()
    {
     
    int i,t;
    int count;
    long long sum,L[100009];
    int N;
   scanf("%d",&t);
    while(t--)
    {
     
    map<int,bool> c;
    sum=0;
    count=0;
    sount=0;
    long long cum=0;
    scanf("%d",&N);
    for( i=0;i<N;i++)
    scanf("%lld%lld",&B[i],&L[i]);
    qrsort(L,0,N-1);
    for(i=0;i<N;i++)
    {
    if(!c[B[i]])
    {count++;
    c[B[i]]=1;
    sum+=count*L[i];}
    else{
    sount++;
    cum+=L[i];
    }
     
    }
    sum=sum+cum*count;
   printf("%lld\n",sum);
    }
    }


