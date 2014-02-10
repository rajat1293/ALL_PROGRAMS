    #include<iostream>
    #include<cstdio>
    #include<map>
    #include<cstdlib>
    using namespace std;
    int sount;
    struct  music{
    	long long B;
    	long long L;
    };
    
    int com(const void * a,const void* b)
    {
    	
    	return  ((music*)a)->L -((music*)b)->L;
    }
    int main()
    {
     
    int i,t;
    int count;
    long long sum;
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
     music s[N];
    for( i=0;i<N;i++)
    scanf("%lld%lld",&s[i].B,&s[i].L);
    qsort(s,N,sizeof(music),com);
    for(i=0;i<N;i++)
    {
    if(!c[s[i].B])
    {count++;
    c[s[i].B]=1;
    sum+=count*s[i].L;}
    else{
    sount++;
    cum+=s[i].L;
    }
     
    }
    sum=sum+cum*count;
   printf("%lld\n",sum);
    }
    }


