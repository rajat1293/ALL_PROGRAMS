#include<iostream>
#include<cstdio>
#include<fstream>
using namespace std;
int main()
{
	char k;
	int c=0;
	ifstream infile;
    infile.open("rajat.txt");
    perror("");
	infile.unsetf(ios::skipws);
    while((infile>>k)){
    	if(k=='\n')
    	c++;
   cout<<k;
   }
 
 //  cout<<EOF;
    cout<<endl<<c;
   // cin.setf(ios::skipws);
	   infile.close();		
}
//the >> operator is a special operator this operator does not take from the input file the whitespaces
//actually it is same working as was with cin as derived from the samme place..
//but get function takes whitespaces as it takes the cahracters..

