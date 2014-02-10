#include<iostream>
using namespace std;
 class student
 {
 	public:
 		int roll;
 		char name[34];
 		int s1,s2,s3,s4,s5;
 		public:
 			int compute_total()
 			{
 				return s1+s2+s3+s4+s5;
 			}
 			void compute_class()
 			{
 				float perc;
 				perc=(float)compute_total()/5;
 				cout << perc;
 				if(perc>=80)
 				cout << "distinction\n";
 				else if(perc>=60)
 				cout << "first class\n";
 				else if(perc>=40)
 				cout << "second class\n";
 				else
 				cout << "fail\n";
 			}
 		
 };
 int main()
 {
 	student st1,st2;
 	cout<<"enter marks of student1\n";
 	cin >> st1.s1>>st1.s2>>st1.s3>>st1.s4>>st1.s5;
 	cout << "enter marks of student2\n";
 	cin >> st2.s1>>st2.s2>>st2.s3>>st2.s4>>st2.s5;
 	st1.compute_class();
 	st2.compute_class(); 	
 }
