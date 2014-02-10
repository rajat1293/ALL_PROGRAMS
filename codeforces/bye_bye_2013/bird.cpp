#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int t;
    cin>>t;
    sort(arr,arr+n);
    int maxi=0;
    int i=0;
    int j=0;
    for(i=0;i<n;i++){
    	j=i+1;
        while ((arr[j]-arr[i])<=t && j<n) 
        j++;
        maxi=max(maxi,j-i); 
    }
    cout<<maxi<<"\n";
    
}
