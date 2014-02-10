//AUTHOR ---RAJAT GAMBHIR------
//  ...COPYRIGHTS... RESERVED..
//DATE
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
class fault
{ 
public:
	int C;
	int a[202];
	
};
int main()
{
	int arr[202]={0},gg,N,S;
	scanf("%d%d",&N,&S);
	fault ob[S];
	for(int i=0;i<S;i++)
	{
	scanf("%d",&ob[i].C);
	for(int j=0;j<ob[i].C;j++)//i is the server no
	{
		scanf("%d",&gg);
		ob[i].a[gg]=1;
	}
}
  for(int i=0;i<S;i++ )
  {
  	
  	for(int j=0;j<N;j++)
  	{
  	
  		if(ob[i].a[j]==1)
  		{
  	arr[j]++;
  		}
  		
  	}
  }  
  int k=arr[0];
  int dd=0;
for(int i=1;i<N;i++)
{ 
if(arr[i]<k)
{
	k=arr[i];
	dd=i;
}	
}
//for(int i=0;i<N;i++)
//printf(" ...%d... ",arr[i]);
printf("%d\n",k);
int z=1;
for(int i=0;i<S;i++)
{
	 if(z<=k){
  if(ob[i].a[dd]==1)
{
   printf("%d\n",i);
   z++;  	
}
}
else
break;
}
}

