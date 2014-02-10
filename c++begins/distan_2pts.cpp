#include<iostream>
using namespace std;
#include<math.h>
class point
{
private:
	int x,y;
	public:
		point(int a,int b)
		{
			x=a;
			y=b;
		}
		float compute_dist(point p2)
		{
		float d;
		d= sqrt((x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y));
		return d;	
		}
		
		
};
main()
{int a,b,c,d;
cout<<"enter the points u want to cal the dist\n";
cin>>a>>b>>c>>d;	
point p1(a,b),p2(c,d);
cout<<endl<<"the dist is "<<p1.compute_dist(p2);	
}
