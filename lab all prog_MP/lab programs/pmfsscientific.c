#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
main()
{
      int a,m,n; float x,y,z;
      printf("Hi! Welcome\n");
      printf("Press:\n\t");
      printf("1) for arithmetic operations\n\t");
      printf("2) for scientific calculations\n");
      scanf("%d",&a);
 switch(a){
 case 1:
      printf ("enter any two numbers\n");
      scanf("%f%f",&x,&y);
      printf("Press:\n\t");
      printf(" 1) for addition\n\t 2) for subtraction\n\t 3) for multiplication\n\t 4) for divison\n\t");
      scanf("%d",&m);
      switch(m)
      {case 1:    
      z=x+y;
      printf(" \taddition of the numbers is %f",z); break;
      case 2:
      z=x-y;
      printf("\tsubtraction of the numbers is %f",z); break;
      case 3:
      z=x*y;
      printf("\t multiplication of the numbers is %f",z);
      break;
      case 4:
      z=x/y;
      printf("\tdivison of the numbers is %f",z);
      break;
      default:
      printf("\tinvalid option\n");   }break;
 case 2:
      printf("Press:\n\t");
      printf(" 1) for sine\n\t 2) for cosine\n\t 3) for tangent\n\t 4) for log\n\t 5) for  power\n\t 6) for square root\n");
      scanf("%d",&n);
switch(n)
{case 1:   
      printf("enter angle in radian\n\t");
      scanf("%f",&x); 
      z=sin(x);
      printf("sin(%f)=%f",x,z);     
      break;      
      case 2:
           printf("enter angle in radian\n\t");
      scanf("%f",&x); 
      z=cos(x);
      printf("cos(%f)=%f",x,z);     
      break;       
      case 3:
           printf("enter angle in radian\n\t");
      scanf("%f",&x); 
      z=tan(x);
      printf("tan(%f)=%f",x,z);     
      break;    
      case 4:
           printf("enter value\n\t");
      scanf("%f",&x); 
      z=log(x);
      printf("log(%f)=%f",x,z);     
      break; 
      case 5:
           printf("enter values in the way as (2,3)=8\n\t");
      scanf("%f%f",&x,&y); 
      z=pow(x,y);
      printf("pow(%f,%f)=%f",x,y,z);     
      break;        
      case 6:
                printf("enter value\n\t");
      scanf("%f",&x); 
      z=sqrt(x);
      printf("sqrt(%f)=%f",x,z);     
      break;   
      default:
               printf("invalid option");}break;
               default:
                          printf("invalid option"); }   
                                getch();}
