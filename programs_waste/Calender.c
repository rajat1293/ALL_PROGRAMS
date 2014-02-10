#include<stdio.h>
#include<stdlib.h>
main()
{
    int n,m,k=1,i,j;
    printf("Enter the number of days you want in the month:");
    scanf("%d",&n);
    if(n>31||n<28){
    printf("Invalid option\nExiting...");
    exit(1);}
    printf("Enter the first day of your month i.e. press\n 1 for MON\n 2 for TUE\n 3 for WED\n 4 for THUR\n 5 for FRI\n 6 for SAT\n 7 for SUN\n");
    scanf("%d",&m);
    printf("\tMON\tTUE\tWED\tTHUR\tFRI\tSAT\tSUN\n");
    for(j=1;j<m;j++)
        printf("\t");
    for(i=m;i<8;i++)
    {

      printf("\t%d",k);
      if(i==7)
      {
          printf("\n");i=0;
    }
      if(k==n)
      break;k++;
    }

}
