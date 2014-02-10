#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	enum {max=34
	};
	char filee[max];
cout<<"enter the filename s rajat1.txt";
cin>>filee;
ifstream infile;
infile.open(filee);
int s=0,i=0;
int h=0;
char k,m;
while((infile))//not while(infile)
{ i++;
//infile.get(k);
k=infile.get();
cout<<k<<endl;
//cout<<i<<endl;
s+=(k-48);
//cout<<s<<endl;
if(k>h)
h=k;		
}
float av=(static_cast<float>(s)/i);	
cout<<"the average is "<< av;
cout<<endl<<"highest number is"<<(char)h;		
infile.close();
}
//when it extracts the last operand from the file reaches the  end but the character is not read 
// so to read the character it goes into the loop but this time there is null so unsuceeful reding takes place so the 
//value in s+=k goes to be same as the last value..so use this or check flag bit9
//as the file contains sapce we cant use get()
//doubts
// both get reading an xtra spaca here
