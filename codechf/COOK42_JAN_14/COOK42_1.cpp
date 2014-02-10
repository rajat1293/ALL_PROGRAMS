#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct rect{
	int left,right,bottom,top;
};


int main(){
	int t;
	cin>>t;
	while(t--){
		rect r1,r2;
		int area1,area2,area;
		int left,right,bottom,top;
		cin>> r1.left>>r1.bottom>>r1.right>>r1.top;
		cin>> r2.left>>r2.bottom>>r2.right>>r2.top;
		area1= abs(r1.right-r1.left)*abs(r1.top-r1.bottom);
		area2= abs(r2.right-r2.left)*abs(r2.top-r2.bottom);
		left = max(r1.left, r2.left);
		right = min(r1.right, r2.right);
		bottom = max(r1.bottom, r2.bottom);
		area = area1+area2;
		top = min(r1.top, r2.top);
		if(left < right && bottom < top){
			area = area - abs(right-left)*abs(top-bottom);
		}
		cout<<area<<endl;
	}	
}
