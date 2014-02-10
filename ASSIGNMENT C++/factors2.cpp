#include<iostream>
using namespace std;
int div(int n,int divv)
{int rem;
	if(divv>n)
	return 0;
	else
	{
		rem=n%divv;
		div(n,divv+2);
		if(rem==0)
		cout<<divv<<"\t";
	}
}
int main()
{
	char c;
	int n;
	do{
	cout<<"enter an integer\n";
	cin>>n;
	if(n%2){
	cout<<"no even divisors\n";
	continue;}
	cout<<"even divisors are\n";
	div(n,2);
	cout<<"\nto continue press y \n";
	cin>>c;
}while(c=='y');
return 0;
}
