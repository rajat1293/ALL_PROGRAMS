#include<iostream>
using namespace std;
class toolbooth
{
unsigned int car;
double money;
public:
	void cer(int);
toolbooth():car(0),money(0)//bbok styl
{}
void payingcar()
{
car++;
money+=2.5;
}
void nopaying()
{
car++;
}
void disp()
{
cout<<"total amount is"<<money;
cout<<endl<<"total cars are"<<car;
}
};
 void toolbooth::cer(int i)
{

    cout<<"\n1.for paying car\n"
<<"2.for non paying car\n"
<<"3.display\n";
int n;
cin>>n;
switch(n)
{
case 1:
payingcar();
break;
case 2:
nopaying();
break;
case 3:
disp();
break;
default:
cout<<"wrongggg\n";
}
//cout<<"\n1.for paying car\n"<<"2.for non paying car\n"<<"3.display\n";
//cin>>n;
}
main()
{
    toolbooth c[2];
    int k;
    char p;
    do{
cout<<"enter the tool booth no";
cin>>k;
c[k].cer(k);
cout<<"to continue press y"; 
cin>>p;
}while(p=='y');
}//to find the total of paying as well as total cars passed.
// usr is to enter the tool booth he wants and also the type of his car
// switch statement is used
// my name is rajat gambhir
// i study in ni
