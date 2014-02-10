#include<stdio.h>
//see the codechef editorial 
int main()
{
    int t,n,i,fact=1,temp=0,k,j,m,arr[200],x;
    scanf("%d",&t);
    while(t--)
    {
        i=1;
        scanf("%d",&n);
        arr[0]=1;
        m=1;
        /* Initially, a[0] will be 1 and the value of 'm' will be 1 specifying that we have just one digit in the array.*/
        while(i<=n)
        {
            for(j=0;j<m;j++)
            {
                x=(arr[j]*i)+temp;
                arr[j]=x%10;
                temp=x/10;
            }
            while(temp>0)
            {
                arr[j]=temp%10;
                temp=temp/10;
                j++;
                m++;
            }
            i++;
        }
        for(k=m-1;k>=0;k--)
            printf("%d",arr[k]);
        printf("\n");
    }
    return 0;
}
