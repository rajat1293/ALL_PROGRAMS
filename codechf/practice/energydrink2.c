    #include<stdio.h>
    int main()
    {
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n,flag=0;
    scanf("%d",&n);
    int a[n],b[n],c[n],i,j;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int count=0;b[0]=0,c[0]=1;
    for(i=0;i<n;i++)
    {
    if(a[i]>=n-i-1)
    {
    count++;
    break;
    }
    else if(a[i]==0)
    {
    int f=0;
    for(j=i-1;j>=0;j--)
    {
    if(a[j]>=i+1-j)
    {
    f=1;
    // count++;
    i=j-1;
    break;
    }
    }
    if(f==0)
    flag=1;
    }
    else
    {
    i=a[i]+i-1;
    count++;
    }
    }
    if(flag==1)
    printf("32768\n");
    else
    printf("%d\n",count);
    }
    //getch();
    return 0;
    }

