#include<stdio.h>
#include<stdlib.h>
typedef enum{a,c,d,lp,rp,e}pp;
int isp[]={0,12,12,0,15};
int icp []={0,12,12,17,15};
pp gett(char*,int*);
int top=0;
int stack[15];
void printt(int tt);
void push(int);
int pop();
char expp[12];
main()
{
    stack[0]=0;
int n=0,op1,op2;
char k;
pp t;
  printf("enter a infix\n");
  scanf("%s",expp);
  fflush(stdin);
  printf("%s\n",expp);

 for(t=gett(&k,&n);t!=a;t=gett(&k,&n))
  {
      if(t==e)
      printf("%c",k);
      
      else
      if(t==rp)

     {
      while(stack[top]!=lp )
      printt(pop());
      pop();
  }
  else
  {
      while(isp[stack[top]]>=icp[t])
      printt(pop());
      push(t);
  }
  }
  while((t=pop())!=a)
  printt(t);
  }



pp gett(char *symbol,int *n)
{
    *symbol=expp[(*n)++];
    switch(*symbol)
    {case '+': return c;
    case  '-': return d;
    case '\0':return a;
    case '(': return lp;
    case ')': return rp;
    default : return e;
    }
    }
 void push(int  f)
{
stack[++top]=f;
}
int pop()
{if(top==-1)
{
exit(1);}

 return stack[top--];
}
void printt(int t)
{
   if(t==c)
   printf("+");
   else printf("-");


}





