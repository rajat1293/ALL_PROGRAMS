#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
     char stack[20];
     int T=-1;
     void topost(char in_fix[]);
     void push(char);
     char pop();
     main()
     {
           char in_fix[25];
           puts("enter an infix expression");
           gets(in_fix);
           puts("\n postfix expression");
           topost(in_fix);
           }
           void push(char s)
           {
                if(T>=19)
                {
                         puts("\nstack overflow");
                         exit(1);
                         }
                         else
                         {T=T+1;
                         stack[T]=s;
                         }
                         }
                         char pop()
                         {
                                  char num;
                if(T==-1)
                {
                         puts("stack is empty");
                         getch();
                         return(0);
                         }
                         else
                         {
                             num=stack[T];
                             T--;
                             }
                             return(num);
                             }
            int prefix(char ch)
            {
             if(ch=='/')return(5);
             else if (ch=='*') return(4);
             else if (ch=='+') return(3);
             else return (2);
             }
             void topost(char in_fix[])
             {
                  int len;
                  static int index =0,pos=0;
                  char s,t;
                  char postfix[40];
                  len=strlen(in_fix);
                  push('#');
                  
          while(index<len)
          s=in_fix[index];
          switch(s)
          {

case'(': push(s);break;
                   case')':t=pop();
                   while(t!='(')
                   {
     postfix[pos]=t;
     pos++;
     t=pop();
     }
     break;
     case'+':
     case'-':
     case'*':
     case'/':
     case'^':
     while(prefix(stack[T])>prefix(s))
     {
       t=pop();
       postfix[pos]=t;
       pos++;
       }
       push(s);break;
       default: postfix[pos++]=s;break;}
       index++;
       
       while (T>0)
       {
                 t=pop();
                 postfix[pos++]=t;
                 }
           postfix[pos++]='\0';
           puts(postfix);
           return;
           }
                 
                   
                                            
                                                        
     
          

