//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a;
		scanf("%d",&a);
		if(360%(180-a)==0)
		printf("YES\n");
		else 
		printf("NO\n");
	}
}

