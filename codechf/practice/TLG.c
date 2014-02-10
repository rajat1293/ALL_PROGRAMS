    #include<stdio.h>
    #include<stdlib.h>
    int main()
    {
    int n,x,y,k,sum1=0,sum2=0,diff=0,big=0,win;
    scanf("%d", &n);
    while(n--){
    scanf("%d %d", &x, &y);
    sum1+=x;
    sum2+=y;
    diff = sum1-sum2;
    if(big<(k=abs(diff))){
    big=k;
    if(diff>0)
    win =1;
    else
    win = 2;
    }
    }
    printf("%d %d",win, big);
    return 0;
    } 
