#include<stdio.h>
#include<conio.h>
 struct boo{
             int rows;
             int col;
             int value;
             };             
       void fftt(struct boo[], struct boo[]) ;
                        
    int   main()
{          
           int i;
         struct boo b[9]; 
      struct boo  a[9]={{6,6,8},
                          {0,0,15},
                          {0,1,22},
                          {1,5,-15},
                          {1,1,11},
                          {1,2,3},
                          {2,3,-6},
                          {4,0,91},
                          {5,2,28}};
             for(i=0;i<9;i++)
             printf("\n%d  %d  %d",a[i].rows,a[i].col,a[i].value);
             fftt(a,b);
             printf("\n the transpose is \n");
             for(i=0;i<=8;i++)
             printf("%d  %d  %d\n",b[i].rows,b[i].col,b[i].value);
             getch();
             }
             void fftt(struct boo a[],struct boo b[])
{
         b[0].rows=a[0].col;
         b[0].col=a[0].rows;
         b[0].value=a[0].value;
        int  j,i,ror[6],str[6];
        for(i=0;i<6;i++)
        ror[i]=0;
        for(i=1;i<=8;i++)
        ror[a[i].col]++;
        str[0]=1;
        for(i=1;i<6;i++)
        str[i]=str[i-1]+ror[i-1];
        for(i=1;i<=8;i++)
        {
                        j=str[a[i].col]++;
                        b[j].rows=a[i].col;
                        b[j].col=a[i].rows;
                        b[j].value=a[i].value;
                        }
                        printf("\n the transpose is \n");
             for(i=0;i<=8;i++)
             printf("%d  %d  %d\n",a[i].rows,a[i].col,a[i].value);
                        } 
             
