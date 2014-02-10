#include<iostream>
using namespace std;
#include<string.h>
#define MAX 23
class student
{
	protected:
	char name[MAX],phone_no[MAX];
		int age;
public:		
  void init (char *a,int b,char *p)
	{
		strcpy(name,a);
		strcpy(phone_no,p);
		age=b;	
	}		
};

class enggstud : public student
{
	private:
		char branch[MAX];
		int sgpa1,sgpa2,sgpa3,cgpa;
		public:
		void initt(char *b,int a,int c,int d)
		{
			strcpy(branch,b);
			sgpa1=a;
			sgpa2=c;
			sgpa3=d;
		}
	void cs_cgpa()
	{
		int k;
		k=sgpa1*50+sgpa2*60+sgpa3*70;
		int s;
		s=50+60+70;
		float l;
		l=(float)k/s;
		cout<<"the cgpa is"<<l<<endl;
	     
	}
void check ()
	{
		char *p;
		p=phone_no;
		if(*p==8|| *p==9)
		cout<<"mobile no\n";
		else 
		cout<<"landline no\n";
	}
	char*  branchh()
	{char *p;
	p=branch;
		return p;
	}
	void ece_cgpa()
	{
		int k;
	 k=(sgpa1+sgpa2+sgpa3)/3;
	 cout<<"the cgpa is ece "<<k<<endl;
}
int  young(int c)
{
if(age>c)
c=age;		
return c;
}};

main()
{int i;
int s,b,r,m,n,pp=0;
	cout<<"enter the no of students  ";
	cin>>s;
	enggstud cc[s];
	char a[23],c[23],d[23];
for(i=0;i<s;i++)
	{
		cout<<"enter the name,age and ph no of students";
		cin>>a>>b>>c;
		cc[i].init(a,b,c);
	}
		for(i=0;i<s;i++)
		
		{
			cout<<"enter branch";
		cout<<"enter sgpa1,sgpa2,sgpa3";
		cin>>d;
		cin>>r>>m>>n;
		cc[i].initt(d,r,m,n);
		}
	for(i=0;i<s;i++)
	{
		if(!(strcmp(cc[i].branchh(),"comp")))
		cc[i].cs_cgpa();
		else if(!(strcmp(cc[i].branchh(),"it")))
		cc[i].cs_cgpa();
		else 
		cc[i].ece_cgpa();
	}
	
	for(i=0;i<s;i++)
{
pp=	cc[i].young(pp);	
}
cout<<"youuung is"<<pp;
	
	for(i=0;i<s;i++)
		cc[i].check();
		
		
	}







	

	
	
	
	
		

