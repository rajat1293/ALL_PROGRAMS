#include<iostream>
using namespace std;
class member
{
      private:
      int salary;
      static int k;
      public:
      	static float av_salary(int);
             member() 
             {
             }
             void init(int a)
             {
                  salary = a;
                  }
                  
         void  tot_salary()
           {
               k=k+salary;
               }  
                
                   };
                   int member::k;
                   float member ::av_salary(int a)
                   {
                   	return ((float) k)/a;
                   }
      main()
      {
      int d,i,l;
      float s;
      member b[100];
	  cout<<"enter the no of empleyes\n";
	  cin>>d; 
	  cout<< "enter the salary of each employee\n";
	  for(i=0;i<d;i++)
	  {
	  	cin>> l;
	  	b[i].init(l);
	  	b[i].tot_salary();
	  }
	s=  member::av_salary(d);
	cout<<"....\n"<<s;
	  	 }
	               
                              
                   
                   
                   
                   
                                        
