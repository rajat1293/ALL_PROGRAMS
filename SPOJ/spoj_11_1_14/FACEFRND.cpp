#include <iostream>
#include<stdio.h>
#include <set>
using namespace std;

int main ()
{
  std::set<int> myset;
  int n;int m[102];
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
  	
  	int ss;
	  scanf("%d",&m[i]);
	  int mm;
	  scanf("%d",&mm);
  	for(int i=1;i<=mm;i++)
  {
  	scanf("%d",&ss);
  	myset.insert(ss);
  }
}
int countt=0;
  for(int i=1;i<=n;i++)
  if(myset.find(m[i])!=myset.end())
  	myset.erase(m[i]);
  for(set<int>::iterator it =myset.begin(); it!= myset.end();it++)
  	countt++;
  	printf("%d\n",countt);
}
