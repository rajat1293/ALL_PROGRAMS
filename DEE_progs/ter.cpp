#include<iostream.h>
#include<stdio.h>
int a[10],n;
int terser(int element)
{int low=0;
 int high=(n-1);
 int p1=n/3;
 int p2=(p1+n/3);
 int size=n;
 while(low<high)
 {if(element==a[p1])
  return(p1);
  else if(element==a[p2])
  return(p2);
  else if(element==a[low])
  return(low);
  else if(element==a[high])
  return(high);
  else if(element<a[p1])
  {high=(p1-1);
	size=(high-low);
	p1=(low+size/3);
	p2=(p1+size/3);
  }
  else if(element>a[p2])
  {low=(p2+1);
	size=(high-low);
	p1=(low+size/3);
	p2=(p1+size/3);
  }
  else
  {low=(p1+1);
	high=(p2-1);
	size=(high-low);
	p1=(low+size/3);
	p2=(p1+size/3);
  }
 }
 return(-1);
 }

 void main()
 {cout<<"enter the number of elements in array";
  cin>>n;
  cout<<"\nnow enter the sorted array";
  for(int i=0; i<n;i++)
  cin>>a[i];
  cout<<"\nenter the element to pe searched for:";
  int element,pos;
  cin>>element;
  pos=terser(element);
  if(pos!=-1)
  cout<<"\n\n\nelement found at position:"<<(pos+1);
  else
  cout<<"element not found in list";
 }


