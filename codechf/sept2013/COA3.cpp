//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
////////////////////////
int var;
 int prime[505];
// int cal[504][504];
// marks all mutiples of 'a' ( greater than 'a' but less than equal to 'n') as 1.
void markMultiples(bool arr[], int a, int n)
{
    int i = 2, num;
    while ( (num = i*a) <= n )
    {
        arr[ num-1 ] = 1; // minus 1 because index starts from 0.
        ++i;
    }
}
 
// A function to print all prime numbers smaller than n
void SieveOfEratosthenes(int n)
{
prime[0]=0;
prime[1]=0;
    // There are no prime numbers smaller than 2
    if (n >= 2)
    {
        // Create an array of size n and initialize all elements as 0
        bool arr[n];
        memset(arr, 0, sizeof(arr));
 
        /* Following property is maintained in the below for loop
           arr[i] == 0 means i + 1 is prime
           arr[i] == 1 means i + 1 is not prime */
        for (int i=1; i<n; ++i)
        {
            if ( arr[i] == 0 )
            {
                //(i+1) is prime, print it and mark its multiples
               var++;
               prime[i+1]=var;
                markMultiples(arr, i+1, n);
            }
            else
            prime[i+1]=prime[i];
        }
    }
}
 

///////////////////////
	int Top[504][504],Bot[504][504],Left[504][504],Right[504][504];
	
	int main()
{	
	SieveOfEratosthenes(500);
	int t;
	scanf("%d",&t);
	char  A[504][504];
	for(int i=0;i<=502;i++)
{
	A[i][0]='#';
	A[0][i]='#';
}
	while(t--)
{
	int r,c,ret,min=0,sum=0;
	scanf("%d%d",&r,&c);
	for(int i=1;i<=r;i++)
{ 
	//fflush(stdin);
	for(int j=1;j<=c;j++)
	cin>>A[i][j];
	//scanf("%c",&A[i][j]);
}
	for(int i=0;i<=502;i++)
{
//	A[i][0]='#';
//	A[0][i]='#';
	A[i][c+1]='#';
	A[r+1][i]='#';
}
	
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
{
	if(A[i][j]=='#'||(A[i][j-1]=='#'))
	Left[i][j]=0;
	else 
	Left[i][j]=Left[i][j-1]+1;
}
//////
	for(int i=1;i<=r;i++)
	for(int j=c;j>=1;j--)
{
	if(A[i][j]=='#'||(A[i][j+1]=='#'))
	Right[i][j]=0;
	else 
	Right[i][j]=Right[i][j+1]+1;
}

//////
	for(int i=1;i<=c;i++)
	for(int j=1;j<=r;j++)
{
	if(A[j][i]=='#'||(A[j-1][i]=='#'))
	Top[j][i]=0;
	else 
	Top[j][i]=Top[j-1][i]+1;
}
	
//////
	for(int i=1;i<=c;i++)
	for(int j=r;j>=1;j--)
{
	if(A[j][i]=='#'||(A[j+1][i]=='#'))
	Bot[j][i]=0;
	else 
	Bot[j][i]=Bot[j+1][i]+1;
}
///-------------------
/*	for(int i=1;i<=r;i++)
	{
	for(int j=1;j<=c;j++)
		cout<<Left[i][j]<<" ";
		cout<<endl;	

}
cout<<endl;

	for(int i=1;i<=r;i++)
	{
	for(int j=1;j<=c;j++)
		cout<<Right[i][j]<<" ";
		cout<<endl;
}
cout<<endl;

	for(int i=1;i<=r;i++)
	{
	for(int j=1;j<=c;j++)
		cout<<Top[i][j]<<" ";
		cout<<endl;
}
cout<<endl;

	for(int i=1;i<=r;i++)
	{
	for(int j=1;j<=c;j++)
		cout<<Bot[i][j]<<" ";
		cout<<endl;
}
cout<<endl;
*/
	////------------------
	for(int i=1;i<=r;i++)
	for(int j=1;j<=c;j++)
{
	min=Left[i][j];
	if(Right[i][j]<min)
	min=Right[i][j];
	if(Top[i][j]<min)
	min=Top[i][j];
	if(Bot[i][j]<min)
	min=Bot[i][j];
	sum+=prime[min];	
}
printf("%d\n",sum);
}
}


