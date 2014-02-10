#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
vector<int> zero(vector<int> a)
{
    bool f=false;
    int size=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        if(a[i]!=0)
        {
            f=true;
            size=i;
            break;
        }
    }
    if(f)
    {
        vector<int> b(size+1);
        for(int i=0;i<size+1;i++)
            b[i]=a[size-i];
        return b;
    }
    else
        return a;
}
/// a+b
vector<int> sum(vector<int> a,vector<int> b)
{
    if(a.size()>b.size())
    {
        vector<int> rez(3000);
        int a_end=a.size()-1;
        int remainder=0,k=0,ans;
        for(int i=b.size()-1;i>=0;i--)
        {
            ans=a[a_end]+b[i]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            a_end--;
        }
        int kk=k;
        for(int i=a.size();i>kk;i--)
        {
            ans=a[a_end]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            a_end--;
        }
        if(remainder!=0)
            rez[k]=remainder;
        return zero(rez);
    }
    else
    {
        vector<int> rez(3000);
        int b_end=b.size()-1;
        int remainder=0,k=0,ans;
        for(int i=a.size()-1;i>=0;i--)
        {
            ans=b[b_end]+a[i]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            b_end--;
        }
        int kk=k;
        for(int i=b.size();i>kk;i--)
        {
            ans=b[b_end]+remainder;
            if(ans>9)
            {
                rez[k]=ans%10;
                remainder=ans/10;
            }
            else
            {
                rez[k]=ans;
                remainder=0;
            }
            k++;
            b_end--;
        }
        if(remainder!=0)
            rez[k]=remainder;

        return zero(rez);
    }
}
/// a & b comparison
int compare(vector<int> a,vector<int> b)
{
    if(a.size()>b.size())
        return 1;
    if(b.size()>a.size())
        return 2;
    int r=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>b[i])
        {
            r=1;
            break;
        }
        if(b[i]>a[i])
        {
            r=2;
            break;
        }
    }
    return r;
}
/// a-b
vector<int> subtraction(vector<int> a,vector<int> b)
{
    vector<int> rez(1000);
    int a_end=a.size()-1;
    int k=0,ans;
    for(int i=b.size()-1;i>=0;i--)
    {
        ans=a[a_end]-b[i];
        if(ans<0)
        {
            rez[k]=10+ans;
            a[a_end-1]--;
        }
        else
            rez[k]=ans;
        k++;
        a_end--;
    }
    int kk=k;
    for(int i=a.size();i>kk;i--)
    {
        ans=a[a_end];
        if(ans<0)
        {
            rez[k]=10+ans;
            a[a_end-1]--;
        }
        else
            rez[k]=ans;
        k++;
        a_end--;
    }
    return zero(rez);
}
/// a div b
vector<int> div(vector<int> a,vector<int> b)
{
    vector<int> rez(a.size());
    rez=a;
    int comp=-1;
    vector<int> count(1000);
    vector<int> one(1);
    one[0]=1;
    while(comp!=0 || comp!=2)
    {
        comp=compare(rez,b);
        if(comp==0)
            break;
        rez=subtraction(rez,b);
        count=sum(count,one);
    }
    count=sum(count,one);
    return count;
}

