#include<iostream>
using namespace std;
int main()
{
	long long ret=0;
		int t;
		cin>>t;
	while(t--){
		int A[100002];
		int N;
		cin>>N;
		for(int i=0;i<N;i++)
		cin>>A[i];
for (int i=0, p=1; i<30; i++, p<<=1) {
            int c=0;
            for (int j=0; j<=N; j++) {
                if (A[j]&p) c++;
            }
            ret += (long long)c*(N-c+1)*p;
        }
        cout<<ret<<endl;
    }
}

