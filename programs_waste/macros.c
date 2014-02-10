#include<stdio.h>
#include<math.h>
#define DISP(f,x) printf("f(%g)=%g\n",x,f(x));
main(){
    int a;
    float d;
    printf("Enter the value of x to calculate f(x)\n");
    scanf("%f",&d);
    printf("What you want to do with x?\n");
    printf("Press:\n 1 for sqrt\n 2 for cbrt\n 3 for log\n 4 for sin\n 5 for cos\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1:
        DISP(sqrt,d)
         break;
         case 2:
        DISP(cbrt,d)
         break;
         case 3:
        DISP(log,d)
         break;
         case 4:
        DISP(sin,d)
         break;
         case 5:
        DISP(cos,d)
         break;
         default:
         printf("Invalid entry");}
}
