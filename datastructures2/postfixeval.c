#include<stdio.h>
#include<stdlib.h>
typedef enum{a,c,d,e}pp;
pp gett(char*,int*);
int top=-1;
int stack[15];
void push(int);
int pop();int p=0;
char expp[12];
main()
{
int n=0,op1,op2;
char k;
pp t;
  printf("enter a postfix\n");
  scanf("%s",expp);
  fflush(stdin);
  printf("%s\n",expp);
  t=gett(&k,&n);
  printf("%djjj\n",t);
  while(t!=a)
  {printf("\n%diii\n",t);
      if(t==e)
      {p++;
      push(k-'0');
      if(p==3)
      {
       exit(1);}
      }
  else{
  op2=pop();
  op1=pop();
  switch(t){

  case c :
  printf(",,,,,");
  push(op1+op2);
  printf(",,,,,");
  break;


  case d: push (op2-op1);
break;

  }
}

t=gett(&k,&n);
printf("%dlll\n",t);
}
printf("%dooo\n", pop());


}
pp gett(char *symbol,int *n)
{
    *symbol=expp[(*n)++];
    switch(*symbol)
    {case '+': return c;
    case  '-': return d;
    case '\0':return a;
    default :return e;}
    }
 void push(int  f)
{
stack[++top]=f;
printf("\nnn%dkkkk\n",stack[top]);
}
int pop()
{if(top==-1)
{
exit(1);}
printf("hhh");
 return stack[top--];
}




