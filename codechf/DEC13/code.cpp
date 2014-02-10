#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct cyph
{
	char ch;
	int val;
 bool operator() (const cyph & a,const cyph &b)
 {
 	if(a.val==b.val)
 	  return a.ch<b.ch;
	 return a.val<b.val;
 }	
};
int main()
{
	int t;
	cin>>t;
//	freopen("rajat.txt","w",stdout);
	while(t--)
	{
		char chh[2];
		char input[30];
		cin>>input;
		cyph cyy[30];
		
		for(int i=0;i<=25;i++)
	{
		cyy[i].ch=(97+i);
		cyy[i].val=0;
	}
		
		gets(chh);
		char cyper[150004];
		gets(cyper);
		int i=0;
		while(cyper[i]!=0)
		{
			if(cyper[i]<=90&&cyper[i]>=65)
				cyy[cyper[i]-65].val++;
			else if(cyper[i]<=122&&cyper[i]>=97)
				cyy[cyper[i]-97].val++;	
				i++;
		}
		sort(cyy,cyy+26,cyph());
	//	for(int i=0;i<=25;i++)
	//	cout<<cyy[i].val<<" "<<cyy[i].ch<<" "<<input[i]<<" "<<i<<endl;	
		i=0;	
		while(cyper[i]!=0)
		{
		if(cyper[i]<=90&&cyper[i]>=65)
			{
				for(int j=0;j<=25;j++)
				{
					if(cyy[j].ch==cyper[i]+32)
					cout<<(char)(input[j]-32);
				}
			}
		else if(cyper[i]<=122&&cyper[i]>=97)	
			{
				for(int j=0;j<=25;j++)
					{
						if(cyy[j].ch==cyper[i])
						cout<<input[j];
					}
			
			}
		else 
			{
				cout<<cyper[i];
			}
			i++;
		}
		cout<<endl;
	}	
}
