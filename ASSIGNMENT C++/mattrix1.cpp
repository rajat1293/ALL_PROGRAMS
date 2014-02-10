#include<iostream>
using namespace std;
const int MAXX=50;
class matrix
{
	int n; 
	int arr[MAXX][MAXX];
	public:
	matrix(int k=0):n(k)	
	{
	}
	void get()
	{
		cout<<"enter the elments\n";
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		cin>>arr[i][j];
	}
	void sum();
	void diag();
};
void matrix::sum()
	{
		int usum=0,lsum=0;
	for(int i=0;i<n;i++)
	for(int j=i;j<n;j++)
	{usum=usum+arr[i][j];
	lsum=lsum+arr[j][i];	
	}
	cout<<"sum of upper triangular matrix is "<<usum<<endl;
	cout<<"sum of lower triangular matrix is "<<lsum<<endl;
}
void matrix::diag()
{int asum=0,bsum=0;
for(int i=0;i<n;i++)
	{asum+=arr[i][i];
	bsum+=arr[i][n-i-1];}
	cout<<"sum of elements of diagnol 1 is "<<asum<<endl;
	cout<<"sum of elements of diagnol 2 is "<<bsum<<endl;
	
	
}
int main()
{
	int c;
	cout<<"enter the order of matrix\n";
	cin>>c;
	matrix a=matrix(c);
	a.get();
	a.sum();
	a.diag();
	return 0;
}
