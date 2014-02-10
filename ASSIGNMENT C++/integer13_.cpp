#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAXX 10000
long int remain ;
using namespace std;
class integer{
	char a[MAXX];
	public:
		integer(char *x )
		{
			strcpy(a,x);
		}
char* operator *(integer b)
	{
    static char mul[MAXX];
    char c[MAXX];
    char temp[MAXX];
    int la,lb;
    int i,j,k=0,x=0,y;
    long int r=0;
    long sum = 0;
    la=strlen(a)-1;
        lb=strlen(b.a)-1;
   
        for(i=0;i<=la;i++){
                a[i] = a[i] - 48;
        }

        for(i=0;i<=lb;i++){
                b.a[i] = b.a[i] - 48;
        }

    for(i=lb;i>=0;i--){
         r=0;
         for(j=la;j>=0;j--){
             temp[k++] = (b.a[i]*a[j] + r)%10;
             r = (b.a[i]*a[j]+r)/10;
         }
         temp[k++] = r;
         x++;
         for(y = 0;y<x;y++){
             temp[k++] = 0;
         }
    }
   
    k=0;
    r=0;
    for(i=0;i<la+lb+2;i++){
         sum =0;
         y=0;
         for(j=1;j<=lb+1;j++){
             if(i <= la+j){
                 sum = sum + temp[y+i];
             }
             y += j + la + 1;
         }
         c[k++] = (sum+r) %10;
         r = (sum+r)/10;
    }
    c[k] = r;
    j=0;
    for(i=k-1;i>=0;i--){
         mul[j++]=c[i] + 48;
    }
    mul[j]='\0';
    return mul;
}
int operator==(integer b)
{int i;
	if(strlen(a)!=strlen(b.a))
	{cout<<"NOT EQUAL\n";
	return 0;}
	for( i=0;i<strlen(a);i++)
	{
		if(a[i]!=b.a[i])
		break;
	}
	if(i!=strlen(a))
	{
	cout<<"NOT EQUAL\n";
	return 0;}
	else 
	{
	cout<<"EQUAL\n";
	return 0;	
	}	
} 
int operator < (integer b)
{
	if(strlen(a)>strlen(b.a))
	{
		cout<<a;
		return 0;
	}
	if(strlen(b.a)>strlen(a))
	{
	cout<<b.a;
	return 1;}
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]>b.a[i])
		{cout<<a<<endl;
		return 0;}
		else if(b.a[i]>a[i])
		{cout<<b.a<<endl;
		return 1;
		}	
	}
	cout<<"BOTH ARE EQUAL\n";
	return -1;
}
int validate(char num[]){
    int i=0;

    while(num[i]){
         if(num[i] < 48 || num[i]> 57){
             printf("Invalid positive integer: %s",num);
             return 1;
         }
         i++;
    }

    return 0;
}
char* operator /(integer b)
{
	long int divisor =atoi(b.a);
	cout<<divisor;
	static char quotient[MAXX];
    long temp=0;
    int i=0,j=0;

    while(a[i]){
        
         temp = temp*10 + (a[i] -48);
         if(temp<divisor){
            
             quotient[j++] = 48;
            
         }
         else{
             quotient[j++] = (temp / divisor) + 48;;
             temp = temp % divisor;

         }
         i++;
    }

    quotient[j] = '\0';
    remain = temp;
    return quotient;
	
}
};
int main()
{
	char *c,b[MAXX],a[MAXX];
	int choice;
while(1){
	cout<<"1.to multiply\n";
	cout<<"2. to divide\n";
	cout<<"3.to see if both are equal (==)\n";
	cout<<"4.to see which is greater(>)\n";
	cout<<"any other to QUIT\n";
		cin>>choice;
		cout<<"enter the first no\n";
			cin>>a;
			integer ob(a);
			cout<<"\nenter the second no";
			cin>>b;
				integer ob1(b);
	switch(choice){
		case 1:
			c=ob*ob1;
			cout<<endl<<c<<"\n";
             break;
		case 2:
			c=ob/ob1;
			cout<<endl<<c<<"\n";
			break;
			case 3:
				ob==ob1;
				break;
				case 4:
					ob<ob1;break;
					default:exit(8);
						
						}
} 
}
