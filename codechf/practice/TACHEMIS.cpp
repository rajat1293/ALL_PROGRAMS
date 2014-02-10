#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stringstream ss;
        int n = s.size();
        ss << "#";
        for(int i = 0; i < n; i++){
            ss << s[i] << "#";
        }
        string ns = ss.str();

        int ret = 0;

        vector<int> arr(ns.size(), 0);
        int cm = 0;
        int ci = 0;
        for(int i = 0; i < ns.size(); i++){
            int pi = 2 * ci - i;
            int pl = 0;
            if(pi >= 0){
                pl = arr[pi];
            }
            if(i + pl < cm){
                arr[i] = pl;
            }else{
                while(i + pl < ns.size() && i - pl >= 0){
                    if(ns[i + pl] != ns[i - pl]) break;
                    else pl++;
                }
                pl -= 1;
                arr[i] = pl;
                if(pl > cm) cm = pl;
            }
            ret += (arr[i] + 1) / 2;
        }

        return ret;
    }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		string s;
		char ch;
		scanf("%d",&n);
		getchar();
		for(int i=1;i<=n;i++)
		{
			scanf("%c",&ch);
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			s = s + ch;
		}
		printf("%d\n",longestPalindrome(s));
	
	}
	

	
	
}
