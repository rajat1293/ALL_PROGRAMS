#include<iostream>
using namespace std;
#include<string.h>
#define l 2
class employee 
{private:
	int emp_no;
	char emp_name[12],desig[12],dept_name[12];
	float sal;
	static int c;
	public :
		static void set(int);
		void init(int a,char *b,char *c,char *d,float e)
		{
			emp_no=a;
			strcpy(emp_name,b);
			strcpy(desig,c);
			strcpy(dept_name,d);
			sal=e;
			}
			void disp()
			{
				cout<<emp_no<<endl<<emp_name<<endl<<desig<<endl<<dept_name<<endl<<sal;
					
			}
		int	search()
			{
				if(c==emp_no)
				return 1;
				
				
			}
			
	int high()
	{
		if(c<sal)
		c=sal;
		return c;
		
	}		
		};
		int employee::c;
		void employee::set(int a)
		{
			c=a;
					
		} 
		
		main ()
		{
		int b,i,k;
		employee ar[4];
		float d;
		char a[12],c[12],e[12];
		for(i=0;i<l;i++)
			{
			cout<<"enter the employee details of  employees\n";
			cout<<"\nname";
			cin>>a;
			cout<<"\nemp_no";
			cin>>b;
			cout<<"\ndesignation";
			cin>>c;
			cout<< "\nsalary";
			cin>>d;
			cout<<"\ndepartment";
			cin>>e;
			ar[i].init(b,a,c,e,d);
						
		}
		cout<<"\nenter the emp no to be searched\n";
		cin >>b;
		employee::set(b);
		for(i=0;i<l;i++)
		{
		k = ar[i].search();
		if(k==1)
	{
		ar[i].disp();
		break;
		
	}}
	if(i==l)
	{cout<<"no such employee exits\n";
	}
	employee::set(d);
		for(i=0;i<l;i++)
		 k=ar[i].high();
		cout<<"\nsalary highest is"<<k;
		
}


		
			
	
		
		
		
		
			

