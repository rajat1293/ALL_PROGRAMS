#include<iostream>
#include<vector>
#include<stack>
#include<list>
#include<algorithm>
#include<cmath>
using namespace std;

#define MOD 1000000007
#define MAX 1000009

stack<pair<int,int> >  stk;
vector<int> arr(MAX+10);


long long cal_fear(vector<int> &arr,int n) {
	
	long long ans = 1;
	
	stk.push(make_pair(1,arr[0]));

	for(int i=1;i<n;i++) {
		
		pair<int,int> tmp = stk.top();
		while(!stk.empty() && arr[i] < tmp.second ) {
				
//			cout << tmp.second << " "  << tmp.first  << " " << i << endl;	
			ans = ( ans * abs((i+1) -tmp.first  + 1) ) %MOD;
			stk.pop();
			if(!stk.empty())
			tmp = stk.top();
		}
		stk.push(make_pair(i+1,arr[i]));
	}	
	
	return ans;
}

int main() {

	int n,k;
	cin >> n >> k;
	
	for(int i=0;i<n;i++)	
		cin >> arr[i];

	cout <<	cal_fear(arr,n) << endl;
} 
