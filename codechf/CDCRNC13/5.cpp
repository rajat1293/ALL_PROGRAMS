#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char *arr[15];
	char b[103];
	arr[2]="ABC";
	arr[3]="DEF";
	arr[4]="GHI";
	arr[5]="JKL";
	arr[6]="MNO";
	arr[7]="PQRS";
	arr[8]="TUV";
	arr[9]="WXYZ";
	int t;
	scanf("%d",&t);
	char *p;
	while(t--)
{
	scanf("%s",&b);
	p=b;
	int count=1;
	char val;
	val= *p;
	int flag=0;
	p++;
	while(*p!=0)
{
		if(((*p)==val&&count<3)||((*p)==val && *p==55&& count<4)||((*p)==val && *p==57 && count<4))
		count++;	
		else  
{
	    if(val=='#');
		else if(val==48)
		cout<<" ";
	    else
		printf("%c",*(arr[val-48]+count-1));
		val= *p;
		count=1;			
}
		p++;		
}
		if(val!='#'&&val!='0')
 		printf("%c\n",*(arr[val-48]+count-1)); 		
		else 
		cout<<"\n";
}	
}	
	
