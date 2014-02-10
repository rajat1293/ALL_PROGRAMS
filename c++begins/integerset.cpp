#include<iostream>
using namespace std;
class integerset
{
	private:
		int a[101];
	public:
		integerset()
		{
			int i;
			for(i=0;i<=100;i++)
			a[i]=0;
			
		}
integerset uunion(integerset arr)
		{ int i;
		integerset c;
			for(i=0;i<=100;i++)
			{
				if(a[i]==1||arr.a[i]==1)
				c.a[i]=1;		
			}
			return c;	
		}
		integerset intersec(integerset arr)
		{
			
			int i;
		integerset c;
			for(i=0;i<=100;i++)
			{
				if(a[i]==1&&arr.a[i]==1)
				c.a[i]=1;	
		}
		return c;
		}
	void insert(int i)
		{
			a[i]=1;
			
		}
		void display()
{
	int i;
for(i=0;i<=100;i++)	
{
	cout<<endl<<i<<"   "<<a[i];
}
	
}
 int equal(integerset arr)
{
	int i;
		for(i=0;i<=100;i++)
			{
				if(a[i]!=arr.a[i])
				break;
}

if(i==101)
return 1;
return 0;
}};
main()
{
	int k;
integerset ob1,ob2,ob3,ob4;
ob1.insert(5);
ob1.insert(6);
ob2.insert(5);
ob2.insert(9);
k=ob1.equal(ob2);
if(k==1)
cout<<"EQUAL";
else
cout<<"NOT  EQUAL";
ob3=ob1.uunion(ob2);
ob4=ob1.intersec(ob2);
ob3.display();
ob4.display();
}
	
	
	

