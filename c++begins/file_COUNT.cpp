#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
	char k;
	int c=0;
	ifstream infile;
    infile.open("rajat1.txt");
    cin.unsetf(ios::skipws);
    while((k=infile.get())!=EOF){
    	if(k=='\n')
    	c++;
   cout<<k;
   }
 //  cout<<EOF;
    cout<<endl<<c;
   // cin.setf(ios::skipws);
	   infile.close();		
}
