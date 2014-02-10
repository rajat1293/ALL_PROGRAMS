#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
main()
{
      int a; float x,y,z;
      printf("press '1' for addition\n,'2' for subtraction\n, '3' for multiplication\n, '4' for divison\n, '5' for sine\n");
      scanf("%d",&a);
 switch(a)
{
       case(1):
      printf ("enter any two numbers");
      scanf("%f%f",&x,&y);
      z=x+y;
      printf(" addition of the numbers is %f",z);
      break;
      case 2:
      printf ("enter any two numbers");
      scanf("%f%f",&x,&y);
      z=x-y;
      printf(" subtraction of the numbers is %f",z);
       break;
      case 3 :
              printf ("enter any two numbers");
      scanf("%f%f",&x,&y);
        z=x*y;
                 printf(" multiplication of the numbers is %f",z);

       break;
       case 4 :
                     printf ("enter any two numbers");
      scanf("%f%f",&x,&y);
      z=x/y;
                       printf(" divison of the numbers is %f",z);
        break;
                       case 5 :
                       printf(" enter angle in radian");
                       scanf("%f%",&x);
                        z=sin(x);
                        printf("%f",z);
                         break;

                    default:
                       printf("invalid caseee");
                       }
                       getch();
                       }
