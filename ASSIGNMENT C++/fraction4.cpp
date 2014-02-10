#include<iostream>
using namespace std;
int hcf(int a,int b)
{
	if(b==0)
	return a;
	else return hcf(b,a%b);
}

void maxx(int*num,int*den,int i,int n )
{
	int k=i,s=0,r=0,hf,ss=0,rr=0;
	s+=num[i];
	r+=den[i];
	ss=s;
	rr=r;
float f=static_cast<float>(s)/r;
i++;	
float max=f;
	while(i<n){
	s+=num[i];
	r+=den[i];
    f=static_cast<float>(s)/r;	
	if(f>max)
	{max=f;
	ss=s;
	rr=r;
    }
	i++; 	
	}
	if(ss>rr)
	hf=hcf(ss,rr);
	else 
	 hf=hcf(rr,ss);
cout<< "largest fraction is"<<ss/hf<<"/"<<rr/hf;	
}
int main()
{
	int n;
	cout<<"enter the number of fractions\n";
		cin>>n;
		cout<<"enter n numerators and denominators\n";
	int num[n],den[n];
	for(int i=0;i<n;i++)
	cin>>num[i]>>den[i];
	cout<<"enter the index you want the max fraction for\n";
	int in;
	cin>>in;
	maxx(num,den,in,n);	
}
