    #include<stdio.h>
    #include<stdlib.h>
    //#include<conio.h>
    inline int input( )
    {
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
    }
    int main(){
    int n,t,c,i,sum;
    t=input();
    while (t--)
    {n=input();
    c=input();
    sum=0;
    for (i=0;i<n;i++)
    {
    sum += input();
    }
    if (c>=sum) puts("Yes");
    else puts("No");
    }
    //getch();
    return 0;
    } 
