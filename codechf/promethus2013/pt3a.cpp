//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
    struct raj{
    int d;
    int p;
    };
    int main()
    {int t;
    cin>>t;
    while(t--)
    {raj a[103];
    int i,n,sum=0;
    cin >>n;
    for(i=1;i<=n;i++)
    cin>>a[i].d;
    for(i=1;i<=n;i++)
    a[i].p=1;
    for(i=1;i<n;i++)
    {
    	if(a[i+1].d>a[i].d&&a[i+1].p<=a[i].p)
    	while(a[i+1].p<=a[i].p)
        a[i+1].p+=1;
		else if(a[i].d>a[i+1].d&&a[i].p<=a[i+1].p)
		while(a[i].p<=a[i+1].p)
		a[i].p+=1;	
    }
    for(i=1;i<=n;i++)
    sum+=a[i].p;
    cout<<sum<<endl;
}
}
