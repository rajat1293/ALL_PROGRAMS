#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int m=0;
int cc(char *p,char *q,int aa ,int bb)//passing the string we dont get length
{
int a[30],b[30];
int i;
for(i=0;i<10;i++)
a[i]=0;
for(i=0;i<10;i++)
b[i]=0;
//while(*p!='\0'){printf("%c",*p);p++;}
//while(*q!='\0'){printf("%c",*q);q++;}
//printf("..%d%d..",aa,bb);
if(aa==bb)
{
for(i=0;i<bb;i++)
{
//printf("...%d %c",a[p[i]-48],p[i]);
//fflush(stdin);
a[p[i]-48]+=1;
//printf("%d",a[p[i]-48]);
}
for(i=0;i<bb;i++)
b[q[i]-48]+=1;
//printf("%d",b[3]);		
}
else 
return 0;
for(i=0;i<10;i++)
{
	if(a[i]!=b[i])
	return 0;
	}
	return 1;
}
int cal( char *a,char * b)
{
	int s=0,aa,bb;
	char p[20],q[20];
	long c,l,k,i;
sscanf(a,"%ld",&c);
//printf("....%ld",c);
sscanf(b,"%ld",&l);
for(i=c+1;i<l;i++)
{
	k=2*i;
	sprintf(p,"%ld",k);
//	printf("nnnnn%s\n",p);
	sprintf(q,"%ld",i);
aa=strlen(p);
bb=strlen(q);
//	printf(".d..d.%s",q);
	s=cc(p,q,aa,bb);
	//	printf("%d",s);
	//	 printf("%d",m);
	if(s)
	{
    //printf("%d",m);	
     m+=1;
}	
	else{ m;
		//printf("%d",m);
		}
}
//printf("%d",m);	
return m ;		
			
	}
	
main()
{ char a[20],b[20];
int ss;
	printf("enter  two no.s whose range is to be found\n");
	scanf("%s %s",a,b);
ss=	cal(a,b);
printf(".....%d",ss);		
}
