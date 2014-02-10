    #include <iostream>
    #include<string.h>
    #include<stdio.h>
    #include<stack>
    using namespace std;
    int priority(char a){
    if(a== '^')
    {
    return 6;
    }
    else if(a == '/')
    return 5;
    else if(a== '*')
    return 4;
    else if(a=='-')
    return 3;
    else if(a== '+')
    return 2;
    else if(a== '(')
    return 0;
     
    }
     
    int main() {
    int t;
    scanf("%d",&t);
    while(t--){
    stack<char> SS;
    char s[402];
    scanf("%s",s);
   // cout<<s;
    char *p;
    p=s;
    while(*p!=0)
    {
    if(*p == '(')
    SS.push(*p);
    else if( *p == ')' ){
    while(SS.top() != '(')
    {
    printf("%c",SS.top());
    SS.pop();
    }
    SS.pop();
    }
    else if( *p <= 97 && *p>= 122)
    printf("%c",*p);
    else{
    while(priority(SS.top())>=priority(*p)&&SS.empty()==0)
    {
    printf("%c",SS.top());
    SS.pop();
    }
    SS.push(*p);
    }
    p++;
	}
    while(SS.empty()==0){
    printf("%c",SS.top());
    SS.pop();
    }
     
    
    }
     
    }
