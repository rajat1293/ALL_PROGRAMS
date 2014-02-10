#include<iostream.h>
#include<stdio.h>
#include<conio.h>

char buffer[20],string[20];
int check(char ch)
{if(ch=='='||ch=='{'||ch=='}'||ch=='+'||ch==' '||ch=='\t'||ch=='-'||ch=='['||ch=='('||ch==')'||ch==']'||ch=='<'||ch=='>'||ch==';')
 return 1;
 else
 return 0;
}

void print(int i, int j)
{int q,w=0;
 cout<<"\n";
 if(i<9&&j<9)
 {if(i<=j)
  {for(q=i;q<=j;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 1\t";
  }
  else if(i>j)
  {for(q=i;q<9;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 1\t";
   for(q=10;q<19;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 2\t";
   for(q=0;q<=j;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 1\t";
  }
 }
 else if(i>9&&j>9)
 {if(i<=j)
  {for(q=i;q<=j;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 2\t";
  }
  else if(i>j)
  {for(q=i;q<19;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 2\t";
   for(q=0;q<9;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 1\t";
   for(q=10;q<=j;q++)
   {string[w++]=buffer[q];
    cout<<buffer[q];
   }
   cout<<" in buffer 2\t";
  }
 }
 else if(i<9&&j>9)
 {for(q=i;q<9;q++)
  {string[w++]=buffer[q];
   cout<<buffer[q];
  }
  cout<<" in buffer 1\t";
  for(q=10;q<=j;q++)
  {string[w++]=buffer[q];
   cout<<buffer[q];
  }
  cout<<" in buffer 2\t";
 }
 else if(i>9&&j<9)
 {for(q=i;q<19;q++)
  {string[w++]=buffer[q];
   cout<<buffer[q];
  }
  cout<<" in buffer 2\t";
  for(q=0;q<=j;q++)
  {string[w++]=buffer[q];
   cout<<buffer[q];
  }
  cout<<" in buffer 1\t";
 }
 string[w]='\0';
 cout<<"\t\tfor: ";
 puts(string);
}

void main()
{clrscr();
 FILE *f1;
 f1=fopen("C:\\TC\\BIN\\EX.CPP","rt");
 int i,si=0,ei=0;
 char ch;
 i=0;
 buffer[i]=getc(f1);
 while(buffer[i]!=EOF)
 { if(check(buffer[i]))
   {if(i==10)
    ei=8;
    else if(i==0)
    ei==18;
    else
    ei=i-1;
    {if(!check(buffer[i-1])&&buffer[i-1]!='\n')
    print(si,ei);
    else ;
    }
    if(check(buffer[i-1])&&buffer[i-1]!='\n')
    {if(i==10)
     si=8;
     else if(i==0)
     si==18;
     else
     si=i-1;
     while(check(buffer[i])&&buffer[i]!=';')
     {if(i==8)
      i=10;
      else if(i==18)
      i=0;
      else
      i++;
      buffer[i]=getc(f1);
     }
     if(i==10)
     ei=8;
     else if(i==0)
     ei==18;
     else
     ei=i-1;
     print(si,ei);
     si=i;
     if(buffer[i]==';')
     {i++;
      buffer[i]=getc(f1);
     }
    }
    else
    {if(i==8)
     i=10;
     else if(i==18)
     i=0;
     else
     i++;
     si=i;
     buffer[i]=getc(f1);
    }
   }
  else
  {if(i==8)
   i=10;
   else if(i==18)
   i=0;
   else
   i++;
   buffer[i]=getc(f1);
  }
 }
 getch();
}




