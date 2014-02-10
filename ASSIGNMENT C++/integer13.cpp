#include<iostream>
#include<cstring>
using namespace std;
class integer{
	char data1[50];
	char data2[50];
	public:
		integer(char *a ,char *b)
		{
			strcpy(data1,a);
			strcpy(data2,b);
			
		}
	void kk(int)
		{
			int s=0;
			int x=strlen(data1);
			int y=strlen(data2);
			int c=0;
			char *f;
			f=new char[50];
			f+=48;
			*f='\0';
			f--;
			for(int i=y-1;i>=0;i--)
			{
				s=0;
				int z=i;
				int ff=y-1;
				for(int j=z;j<=y-1;j++)
			 {
			 	
			 s+=(data2[ff--]-48)*(data1[j]-48);}
			 //cout<<data2[i]-48;
			 //cout<<data1[i]-48;}
			if(c)
			{
			s+=c;c=0;}
			if(s>=10)
			{ c=s/10;
			*f=s%10; 
			f--;
			}
			else
			{
			int m=*f=s;
				f--;
			}	
		}
	f++;
	while(*f!=0)
	{
	cout<< (*f-48);
    f++;
}
}
};
int main()
{ 
   char a[]="23";char b[]="23";
	integer ob(a,b);
	ob.kk(9);
}
