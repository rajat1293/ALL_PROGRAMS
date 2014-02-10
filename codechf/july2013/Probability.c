#include<stdio.h>
inline int input( )
    {
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
    }
double fun(int a,int b)
{
int i,j=1;
double sum=1;
	for(i=a;j<=b;j++,i--)
	{
		sum=sum*i/j;
	}
	return sum;
}
int main()
{
	int t;
	t=input();
	//scanf("%d",&t);
	while(t--)
	{
		double num=0;
		int i,j,k,nt1,nt2,nt3,left,lost1,lost2,lost3,t1,t2,t3,t4;
		//scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
	t1=input();
	t2=input();
	t3=input();
	t4=input();
		
		for(i=0;i<t1;i++)
		{
			if(t4>=i)
			{
			lost1=i;
			left=t4-i;
			nt1=t1-i;
			
		   }
		for(j=0;j<=t2;j++)
		{
			left=t4-i;
			if(left==0)
     		{
			 nt2=t2;
			 lost2=0;
	    	}
     		if(left<j)
     		continue;
		if(left>=j&&left!=0)
		{
		lost2=j;
		left=left-j;
		nt2=t2-j;
     	}
     	if(t3>=left&&left!=0)
		{
		  lost3=left;
		  nt3=t3-left;
		  num=num+fun(t1,lost1)*fun(t2,lost2)*fun(t3,lost3)*(double)(nt1)/(nt1+nt2);
		 //printf("(%d %d %d)\n",nt1,nt2,nt3);
	     }
	     else if(left==0)
	      {
		  		  nt3=t3;
		  		  lost3=0;
			  num=num+fun(t1,lost1)*fun(t2,lost2)*fun(t3,lost3)*(double)(nt1)/(nt1+nt2);
		   //printf("(%d %d %d)\n",nt1,nt2,nt3);
	      }		  
}
}
printf("%lf\n",num/fun(t1+t2+t3,t4));
}
return 0;
}
