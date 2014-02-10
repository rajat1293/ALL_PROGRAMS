
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
    char str[20],m;
    int i=0,k=0,j=0,n=1,d;
    printf("Enter the string\n");
    gets(str);
    fflush(stdin);
    printf("Alphabet   Frequency\n");
    while(*(str+i)!='\0')    {
        for(d=(i-1);d>=0;d--){
        if(*(str+i)==*(str+d))
       {n=0;break;}}
        if(n==1){
         while(*(str+j)!='\0')
            {if(*(str+i)==*(str+j))
             k++;j++;}

             printf("     %c       %d\n",*(str+i),k);}
             k=0;i++;j=0;n=1;
    }
}
