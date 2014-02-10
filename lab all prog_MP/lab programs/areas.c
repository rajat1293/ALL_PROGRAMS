#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
dot(char *point)
{
     int a=0;
     while(*point!='\0')
     {
             if(*point=='.')
             a++;
             else if(*point<=57 && *point>=48);
             else
            { printf("wrong choice");
       return 0;}
             if(a==2)
             {printf("wrong choice");
          return 0;
             }
             point++;}
             return 1;}
                            
check( char *radius)
{
while(*radius!='\0')
                             {
                             printf("ddd..\n");       
                                    if(*radius <=57 && *radius>=48);
                             else
                           { printf("wrong choice\n");
                           return 0;
                             }
                             radius++;}
                             return 1;}
main()
{
      float a,b;
     char length[12],breadth[12],radius[12],side[12],height[12];
      char choice[12];
      int c;
    while(1){  
      printf("\nhere are your choices of various areas you may wish to calculate\n");
      printf("1.area of circle\n");
      printf("2.area of rectangle\n");
      printf("3.area of square\n");
      printf("4.area of paralellogram\n");
      printf("5.area of triangle\n");
      printf("enter choice \n");
      fflush(stdin);
    gets(choice);
    if(check(choice)==0) 
    continue;
    sscanf(choice,"%d",&c); 
      switch(c)
      {
                    case 1 :
                         printf("enter the radius of circle\n");
                         fflush(stdin);
                             scanf("%s",radius);
                             if(dot(radius)==0)
                             continue;
                             sscanf(radius,"%f",&a);
                             printf("the area of circle is %f\n",3.14*a*a);   
                  break;
                  case 2 : printf("\nenter the length and breadth of rectangle\n");
                            scanf("%s%s",length,breadth); 
                           if( dot(length)==0)
                           continue;
                           if(dot(breadth)==0)
                           continue; 
                            sscanf(length,"%f",&a);
                            sscanf(breadth,"%f",&b);                       
                            printf("\nthe area of rectangle is %f\n",a*b);
               break;
               case 3 : printf("enter thge side of square\n");
                         scanf("%s",side);                        
                         if(dot(side)==0)
                         continue; 
                         sscanf(side,"%f",&a);                       
                         printf("\nthe area of square is %f\n",a*a); 
                    break;
                    case 4 :
                              printf("enter the length and the height\n");
                               scanf("%s%s",&length,&height);
                              if( dot(length)==0)
                           continue;
                           if(dot(height)==0)
                           continue;
                               sscanf(length,"%f",&a);
                               sscanf(height,"%f",&b);
                              printf("\nthe area of paralellogram is %f\n",a*b);
                         break;
                    case 5 :  printf("enter the length and height of the triangle\n");
                              scanf("%s%s",length,height);
                               if( dot(length)==0)
                           continue;
                           if(dot(height)==0)
                           continue;
                              sscanf(length,"%f",&a);
                              sscanf(height,"%f",&b);
                              printf("\nthe area of triangle is %f\n",a*b*0.5);
                              break;
                      default: printf("wrong choice ..\n");                           
                              }}}
                                                   
                     
                                         
      
