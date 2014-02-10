    #include<stdio.h>
    int main()
    {	
    int a[10],b,d,i,j,min,minn;
    scanf("%d",&b);
    while(b--)	
    {	
    d=0;
    for(i=0;i<10;i++)	
    {	
    scanf("%d",&a[i]);
    }	
    i=0;
    if(a[i]==0)	
    {
    if(a[1]==0)
    {
    printf("1\n");
    }
    else
    {
    for(j=2;j<=9;j++)
    {
    if(a[j]==0)
    {
    printf("%d\n",j);
    d=1;
    break ;
    }
    }
    if(d!=1)
    {
    printf("10\n");
    }
    }
    }
    else
    {
    for(j=1;j<=9;j++)
    {
    if(a[j]==0)
    {
    printf("%d\n",j);
    d=1;
    break ;
    }
    }
    if(d!=1)
    {
    min = a[1];
    minn = 1;
    for(j=2;j<=9;j++)
    {
    if(a[j]<min)
    {
    min =a[j];
    minn = j;
    }
    }
    if( min >a[0])
    {
    printf("1");
    for(j=1;j<=(a[0]+1);j++)
    {
    printf("0");
    }
    }
    else
    {
    for(j=1;j<=(min+1);j++)
    {
    printf("%d",minn);
    }
    }
    printf("\n");
    }
    }
    }
    return 0;
    }

