//AUTHOR ---RAJAT GAMBHIR------
//DATE
#include<stdio.h>
#include<math.h>
int main()
{	
int t;
scanf("%d",&t);
while(t--)
{
	double  m,pro;
	 double tot;
	scanf("%lf",&m);
	if(m>0.5)
	   pro = (m-m*m)*20000-(10000*m-(2*m-1)*10000);
	else 
	   pro = (m-m*m)*20000-(10000*m);
       tot=10000+pro;
       printf("%lf\n",tot);
}
return 0;
}

