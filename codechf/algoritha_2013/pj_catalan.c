    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #define mod 100003
    //Catalan_number=(2n!)/(n!*(n+1)!)
    long long int Cval[35]={0};
    long long int C( int n ) {
    long long int i;
    if(Cval[n]!=-1) return Cval[n];
    long long int ans = 0;
    if( n == 0 ) ans = 1;
    for( i = 1; i <= n; i++ )
    ans+=C(i-1)*C(n-i);
    return Cval[n] = ans;
    }
    int main()
    {
    long long int t,n,x,i;
    scanf("%lld",&t);
    char m;
    scanf("%c",&m);
    fflush(stdin);
    while(t--)
    {
    	char ra[41];
    	scanf("%s",ra);
    	n=strlen(ra);
    for(i=0;i<=35;i++) Cval[i]=-1;
    x=C(n-1);
    printf("%lld\n",x);
    }
    return 0;
    }
    /* This function calculates (a^b)%MOD
    long long pow(int a, int b, int MOD)
    {
    long long x=1,y=a;
    while(b > 0)
    {
    if(b%2 == 1)
    {
    x=(x*y);
    if(x>MOD) x%=MOD;
    }
    y = (y*y);
    if(y>MOD) y%=MOD;
    b /= 2;
    }
    return x;
    }
    // Modular Multiplicative Inverse
    // Using Euler's Theorem
    //a^(phi(m)) = 1 (mod m)
    // a^(-1) = a^(m-2) (mod m)
    long long InverseEuler(int n, int MOD)
    {
    return pow(n,MOD-2,MOD);
    }
    long long C(int n, int r, int MOD)
    {
    vector<long long> f(n + 1,1);
    for (int i=2; i<=n;i++)
    f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
    }
    int main()
    {
    long long int n,t,o;
    scanf("%lld",&t);
    while (t--)
    {
    scanf("%lld",&n);
    if(n==0) printf("0\n");
    else
    {
    o=C(2*n,n-1,1000000007);
    o/=n;
    o%=100003;
    printf("%lld\n",o);
    }
    }
    return 0;
    }*/ 