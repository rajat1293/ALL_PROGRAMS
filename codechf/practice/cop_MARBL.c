    #include<stdio.h>
    //#include<conio.h>
    main()
    {
    long long int t,n,k,a,b,i,comb;
    scanf("%lld",&t);
    while(t--)
    {
    scanf("%lld%lld",&n,&k);
    if(n==k)
    {
    printf("1\n");
    continue;
    }
    else
    a=n-1;
    b=min(k-1,n-k);
    comb=1;
    for(i=1;i<=b;i++)
    {
    comb=comb*(a--);
    comb=comb/i;
    }
    printf("%lld",comb);
    printf("\n");
    }
    //getch();
    return 0;
    }
    int min(long long int a,long long int b)
    {
    if(a<=b)
    return a;
    else
    return b;
    }

