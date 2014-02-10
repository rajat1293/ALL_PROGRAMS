#include<iostream>
using namespace std;
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int count[4];
      class student 
      {
            private:
            int roll ;
            char name[32];
            int s1,s2,s3,s4,s5;
            public:
            
            void setmarks(int a,int b,int c,int d,int e)
            {
                  s1=a;s2=b;s3=c;s4=d;s5=e;
                  }
                  void setpersonaldetails(int r, char str[])
                  {
                       roll=r;
                       strcpy(name,str);
                       }
                       int  compute_total()
                       {return s1+s2+s3+s4+s5;
                       }
                      void compute_perf()
                      {
                           float perc;
                           perc=compute_total()/5.0;
                           if(perc>=80)
                           {
                                       cout << "distinction\n";
                                       count[0]++;
                                       }
                          else if(perc>= 60)
                          {
                               cout << "first class\n";
                               count[1]++;
                               }
                               else if(perc >=40)
                               {
                                    cout << "second class\n";
                                    count[2]++;
                                    }
                                    else 
                                    {
                                         cout << "fail\n";
                                         count[3]++;
                                         }
                      }
                               };
                               
                       main()
           {
                       int a1,a2,a3,a4,a5;
                       int r,i;
                       char str[34];
                       int n;
                      student st[30];
                      cout << "\n enter the no of students\n";
                      cin >> n;
                      for(i=0;i<n;i++)
                      {
                                      cout << "\nenter name and roll no of student\n"<< i+1;
                                      cin >>str;
                                      cin >> r;
                                       st[i].setpersonaldetails(r,str);
                                      cout << "\nenter the marks of of student\n"<< i+1;
                                      cin >> a1>>a2>>a3>>a4>>a5;
                                      st[i].setmarks(a1,a2,a3,a4,a5);
                                      st[i].compute_perf();               
                      }
                      cout << " \ndistinction students is "<< count[0]<<"\n";
                      cout << "first class "<< count[1]<< "\n";
                      cout << " second class "<< count[2]<< "\n";
                      cout << " fail " << count[3]<< "\n";
                    getch();
           }
                      
                                      
                                      
                                      
                                             
                       
                       
                       
                                   
                                      
                  
                         
