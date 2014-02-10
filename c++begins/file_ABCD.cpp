#include<iostream>
#include<fstream>
using namespace std;
enum{maxx=30};
int main()
{	char filee[maxx];
	cout<<"enter the file name\n";
	cin>>filee;
	ofstream opfile;
	opfile.open(filee,ios::out);
	for(char i=65;i<=90;i++)
	opfile<<" "<<i<<" "<<static_cast<int>(i)<< " "<<static_cast<char>(i+32)<<" "<<i+32<<'\n';
    opfile.close();
}
//a chaar gets converted to int during arithemetic operations and remain in that state
