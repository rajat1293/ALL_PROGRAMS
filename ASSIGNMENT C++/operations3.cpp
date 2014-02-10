#include<iostream>
using namespace std;
void inc(int* a,int A,int B)
{
	for(int i=A+1;i<B;i++)
	a[i]++;
}
int div(int* a,int A,int B)
{	int s=0;
	for(int i=A+1;i<B;i++)
   if(!(a[i]%3))
   s++;
	return s;
}
int main()
{
	int n;
	int A,B;
	cout<<"enter the size of the array\n";
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	arr[i]=0;
		char c;
	do{
		int k;
		cout<<"press 1 for A op B\n";
		cout<<"press 2 for A div B\n";
		cin>>k;
		switch(k){
			case 1:
				cout<<"enter A and B between 0 and "<<n<<endl;
				cin>>A>>B;
				inc(arr,A,B);
				break;
				case 2:
					cout<<"enter A and B between 0 and "<<n<<endl;
					cin>>A>>B;
				cout<<"number of numbers divisible by 3 are "<<div(arr,A,B);
					break;
					default:
						cout<<"wrong choice\n";
		}
		cout<<"\nto continue press y"<<endl;
		cin>>c;
	}while(c=='y');
	
}
