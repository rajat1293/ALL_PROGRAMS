#include<stdio.h>
int main()
{
      int p=0,k,c,a,b,i,n,w;
      scanf("%d",&n); 
    while(n--)
      {
      scanf("%d%d",&a,&b);
      if(a>b)
      {
      	k=a-b;
      	if(k>p)
      	{
      		w=1;
      		p=k;
      		
      	}
      	
      }
      else
      {
      	k=b-a;
      	if(k>p)
      	{
      		w=2;
      		p=k;
      		
      	}
      }}
	  printf("%d %d",w,p);
      return 0;
}
      
