#include<iostream>
using namespace std;
#include<string.h>
class employee
{private:
	char fname[12],lname[12];
	float salary;
	public:
	employee(char *a,char *b,int c)
	{
		strcpy(fname,a);
		strcpy(lname,b);
	if(c>0)	salary=c;
	else salary=0;		
	}	
	float year_sal()
	{
	float k;
		k=salary*12;
		return k;
	}
	
};

main()
{char a[12],b[12];
int c;
cout<<"enter the first name ,last name and salary of 2 employees\n";
cin>>a>>b>>c;
employee c1(a,b,c);
cin>>a>>b>>c;
employee c2(a,b,c);
cout<<"yyearly salarys are"<<c1.year_sal();
cout<<endl<<c2.year_sal();
}
	
	
	
	

