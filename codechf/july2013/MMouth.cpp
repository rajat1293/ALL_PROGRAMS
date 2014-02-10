#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<map>
#include<string>
#define gc getchar
using namespace std;
void scanint(int &x)
{
	register int c=gc();
	x=0;
	int neg=0;
	for(;((c<48||c>57)&&c!='-');c=gc());
	if(c=='-')
	{
		neg=1;c=gc();
	}
	for(;c>47&&c<58;c=gc())
	{
		x=(x<<1)+(x<<3)+c-48;
	}
		if(neg)
		x=-x;
	}
struct node{
	int num,index,sub;
	struct node*link;
};
node* srr[100006],*temp,*temp1;
int a[100006],diff[100006];
int main()
{
 	int t;
	scanint(t);
	//scanf("%d",&t);
	while(t--)
	{
		map<string,int> arr;
		map<string,int> arr1;
		map<string,int> arr2;
		char str[50];
	int i,n,j=0,k,f1,r=0,g,l,f,k1,l1,d;
	//scanf("%d",&n);
	scanint(n);
	for(i=1;i<=n;i++)
	srr[i]=NULL;
	r=n*(n-1)/2;
	for(i=1;i<=n;i++)
	scanint(a[i]);
	//scanf("%d",&a[i]);
	for(i=1;i<n;i++)
	{
	diff[i]=a[i+1]-a[i];
	sprintf(str,"%d",diff[i]);
	arr1[str]++;
	if(arr2[str]==0)
	{
	temp =new node;
	temp->index=i;
	temp->sub=0;
	temp->num=diff[i];
	temp->link=srr[++j];
	srr[j]=temp;
	arr2[str]=j;
	}
	else
	{
	temp =new node;
	temp->index=i;
	temp->sub=0;
	temp->num=diff[i];
	temp->link=srr[arr2[str]];
	srr[arr2[str]]=temp;
    }
}			
	for(i=1;i<=j;i++)
	{
		f=0;
		temp=srr[i];
		sprintf(str,"%d",temp->num);
	    if(arr1[str]>=2)
		{
		while(temp!=NULL)
	    {
	    	f++;
	    	k=temp->index;
	    	k++;
	    	if(k>=n)
			{
				temp=temp->link;
				continue;
		    }
			k1=diff[k];
			f1=k1;
	    	temp1=temp->link;
	    	while(temp1!=NULL)
	    	{
	    	    d=0;
				g=1;
				k1=f1;
				l=temp1->index;
	    		k=temp->index;
	 			l++; 
				 k++;   		
				while(1)
	    		{
	    		l1=diff[l];
	    		if((k1==l1)&&k<n&&l<n)
				{
				if(g<=temp1->sub) 
				g++;
				else  
				{
				r--;
				d++;
			    }
			    }
                else 
			    {
			    	temp1->sub+=d;
				break;
			}
		    l++;
		    k++;
	        k1=diff[k];
		      }
		      temp1=temp1->link;
			   
		}
		temp=temp->link;	
	}
	r=r-f+1;
}
}
printf("%d\n",r);
}
}



