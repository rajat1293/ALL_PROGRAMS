#include<iostream> 
using namespace std; 
#include<stdio.h> 
#include<vector> 
#include<queue> 
#include<iterator> 
struct node{ int i,j; 
int move; };
 bool arr[40][40];
  queue<node> Q; 
  queue<int> S;
  int main() 
  {
  	int count=0;
   int n,x,y,m; 
  cin>>n>>m; 
  int t=n*m-1; 
  
  node nn,f;
   nn.i=0; 
   nn.j=0; 
   Q.push(nn); 
   x=0; y=0; 
   arr[0][0]=true; 
   while(t--) { 
   int a,b; 
   cin>>a>>b; 
   while(1) { 
   nn.j=(y+1)%m; 
   nn.move=3;
   if(nn.j==b && arr[x][nn.j]==false) 
   break; 
    if(arr[x][nn.j])
	 { 
	 nn.i=(x +1)%n;
	 nn.move=1; 
	 nn.j=y;
	 f=Q.front();
	 arr[f.i][f.j]=false;
	 arr[nn.i][nn.j]=true;
	 count++;
	  Q.pop(); 
	  Q.push (nn);
	  S.push(nn.move);
	  x=nn.i;
	  y=nn.j; 
	  }
	   else
	   {
	   	nn.move=3;
	   f=Q.front();
	 arr[f.i][f.j]=false;
	 cout<<f.i<< " "<<f.j;
	 arr[nn.i][nn.j]=true;
	  count++;
	  Q.pop();
	   Q.push(nn);
	  S.push(nn.move);
	   x=nn.i;
	   y=nn.j; 
	   }	   
	    }
	    if(nn.i!=a)
	    {
	    	nn.move=3;
	    	   f=Q.front();
	 arr[f.i][f.j]=false;
	 arr[nn.i][nn.j]=true;
	  count++;
	  Q.pop();
	   Q.push(nn);
	   S.push(nn.move);
	   x=nn.i;
	   y=nn.j; 
		}
	if(nn.i==a)
	{
		nn.move=3;
		count++;
	//	f=Q.front();
	// arr[f.i][f.j]=false;
	 arr[nn.i][nn.j]=true;	 
		Q.push(nn);
		S.push(nn.move);
		x=nn.i;
	   	y=nn.j; 
	   
}
		else
		{ 
	   while(1) { 
	   nn.i=(x+1)%n;
	    nn.move=1;
		if(nn.i==a&&arr[nn.i][y]==false)
		 break;
		  if(arr[nn.i] [y]) {
		   nn.i=x; 
		   nn.j=(y +1)%m;
		   nn.move=3;
		   count++; 
		   f=Q.front();
	 arr[f.i][f.j]=false;
	 arr[nn.i][nn.j]=true;
		   Q.pop() ;
		    Q.push (nn);
			S.push(nn.move); 
			} 
			else{
				 nn.move=1;
			count++; 
			f=Q.front();
	 arr[f.i][f.j]=false;
	 arr[nn.i][nn.j]=true;
			Q.pop();
			 Q.push(nn);
			 S.push(nn.move);
			  x=nn.i;
	   			y=nn.j; 
	   
			  }
			   }
			    nn.move=1;
			   count++;
//			   f=Q.front();
//	 arr[f.i][f.j]=false;
	 arr[nn.i][nn.j]=true;
			   Q.push(nn); 
			   S.push(nn.move);
			    x=nn.i;
			   y=nn.j;
			   }
			  
		}
		cout<<count<<endl;
			   while(!S.empty ()) 
			   { 
			   int d=S.front();
			    cout<<d<<" "; 
				S.pop() ; 								
				} 
				}

