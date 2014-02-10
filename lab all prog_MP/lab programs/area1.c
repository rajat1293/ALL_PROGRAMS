#include<stdio.h>
main()
{
      char *arr[]={"while","else","if","return","break","continue","{",";",",","++","&","&&","*","%","==","=","<="
      FILE *ptr;
      char ch;
      ptr=fopen("areas.c","r");
      if(!ptr)
      {
              printf("file cannot be open");
              exit(1);
              }
              while(1)
              {
                      
