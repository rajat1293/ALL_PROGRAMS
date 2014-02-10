#include<iostream>
using namespace std;
class op
{
private:
	int arr[5];
	public:
	op(int a,int b,int c,int d,int e)
	{
		arr[0]=a;arr[1]=b;arr[2]=c;arr[3]=d;arr[4]=e;
		
	}
	op()
	{
}
op operator []( char* )
{
int lar=0;
for(int i=1;i<5;i++)
{
	if(arr[i]>arr[lar])
	lar=i;
}	
op s;
s.arr[0]=arr[lar];
return s;	
}
 void display()
 {
 	cout<<arr[0];
 	
 }};
main()
{
	op ob(4,5,2,6,1);
	op c;
	char s[]="rah";
	c = ob[s] ;
	c.display();	
}

