#include<iostream>
using namespace std;
    struct boo{
             int rows;
             int col;
             int value;
             }a[9];
                                     
    int   main()
{          
           
           int i,j;
           int curr=1;
          
             
      struct boo a[9]={{6,6,8},
                          {0,0,15},
                          {0,3,22},
                          {0,5,-15},
                          {1,1,11},
                          {1,2,3},
                          {2,3,-6},
                          {4,0,91},
                          {5,2,28}};
             for(i=0;i<9;i++)
             cout<<"{"<<a[i].rows<<","<<a[i].col<<","<<a[i].value<<"}\n";
             struct boo b[9];
         b[0].rows=a[0].col;
         b[0].col=a[0].rows;
         b[0].value=a[0].value;
         for(i=0;i<a[0].col;i++)
         {
         	for(j=1;j<=a[0].value;j++)
         	{
         		if(a[j].col==i)
         		{
         			b[curr].col=a[j].rows;
         			b[curr].rows=a[j].col;
         			b[curr].value=a[j].value;
         			curr++;
         		}
         			
         		}
         		
         		
         	}
         	
         	cout<<"the transpose is \n";
          for(i=0;i<9;i++)
             cout<<"{"<<b[i].rows<<","<<b[i].col<<","<<b[i].value<<"}\n";	
         }
         
    
