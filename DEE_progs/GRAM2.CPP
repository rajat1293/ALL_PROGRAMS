#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>

char term[10],nterm[10],stack[20];
int top;
struct rule
{char lp[10];
 char rp[10];
}table[10][10];

int searcht(char c,int s)
{for(int i=0;i<s;i++)
 if(term[i]==c)
 return(i);
 return(-1);
}



int searchn(char c,int s)
{for(int i=0;i<s;i++)
 if(nterm[i]==c)
 return(i);
 return(-1);
}

void main()
{clrscr();
 stack[0]='$';
 stack[1]='e';
 top=1;
 int i,j;
 cout<<"enter the number of terminal and non terminal symbols\n";
 cin>>i;
 cout<<endl;
 cin>>j;
 cout<<"enter the terminal symbols:";
 gets(term);
 cout<<"enter the non terminal symbols:";
 gets(nterm);
 int q,w;
 char string[20];
 cout<<"\nenter the production rules";
 cout<<"\nin case of no rule put a '_'\nin case of a null enter '!'\n";
 for(w=0;w<j;w++)
 for(q=0;q<i;q++)
 {cout<<"enter the production rule for "<<term[q]<<" and "<<nterm[w];
  cout<<"\nenter the left part:\n";
  gets(table[q][w].lp);
  cout<<"\nenter right part:";
  gets(table[q][w].rp);
 }
 clrscr();
 int p=0;
 char s='y';
 while(s=='y'||s=='Y'){
 cout<<"enter the string followed by a '$'";
 p=0;
 gets(string);
 q=w=0;
 int e,r,a,s;
 while(string[q]!='$'||stack[top]!='$')
 {while(searchn(stack[top],j)!=-1)
  {e=searchn(stack[top],j);
   r=searcht(string[q],i);
   if(table[r][e].rp[0]=='_')
   {cout<<"grammar error";
    getch();
    exit(0);
   }
   else if(table[r][e].rp[0]=='!')
   top--;
   else
   {a=s=0;
    top--;
    a=strlen(table[r][e].rp);
    for(s=a-1;s>=0;s--)
    stack[++top]=table[r][e].rp[s];
   }
  }
  if(searcht(stack[top],j)!=-1)
  {top--;
   q++;
  }
  p++;
  if(p>1000)
  {cout<<"exception";
   getch();
   exit(0);
  }
 }
 if(stack[top]=='$')
 cout<<"string accepted";
 else
 cout<<"string rejected";
 cout<<"\nenter new??";
 cin>>s;
 q=w=0;
 stack[0]='$';
 stack[1]='e';
 top=1;
 getch();
 }
 getch();
}





