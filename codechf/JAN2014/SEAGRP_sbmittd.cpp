#include<utility>
#include <stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
const int JAADA =100;
const int undef= -2;
 const int empty= -1;
const int  noEdge= 0;
const int unmatched =1;
const int matched =2;
const int  aage =0;
const int reverse =0;
using namespace std;
struct edge {
	int a,b;
};
#define GETCHAR getchar//_unlocked
void sit(){
	map< pair<int,int>, bool> Map;
		int n,m;
		cin>>n>>m;
		int c_m;
		edge e[m+2]; 
		for(int i=1;i<=m;i++)
			cin>>e[i].a>>e[i].b;
		if(n%2)
		{
			cout<<"NO\n";
			//continue;
		}
		if(m<n/2){
			cout<<"NO\n";
			//continue;
		}
		c_m=m;
		for(int i=1;i<=m;i++)
		{
			if(Map[make_pair(e[i].a,e[i].b)]){
				c_m--;
			}
			else
				Map[make_pair(e[i].a,e[i].b)]=true;
		}
		if(c_m<n/2){
			cout<<"NO\n";
			//continue;
		}
		if(1)
			cout<<"YES\n";
		else
			cout<<"NO\n";		
	
}
int fun(edge e[],int i,int n,int count){
	if(count==n)
		return 1;
	if(i == n+1)
		return 0;
		return fun(e,i+1,n,count);
	if(2);
	else{		
		//visit[e[i].a] = 1;		
		//visit[e[i].b] = 1;	
		count+=2;
		int bb= fun(e,i+1,n,count);
		//visit[e[i].a] = 0;
		//visit[e[i].b] = 0;
		count-=2;
		int aa=fun(e,i+1,n,count);
		return aa||bb;
	}	
}

 
inline int readInt()
{
int flag=1;
int n = 0;
char c;
while (1)
{
c=GETCHAR();
if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
else if(flag!=1) break;
}
return n;
}



struct Label {     
       int even;   
       int odd[2];  
};                  
                   
        
struct elem {            
       int vertex,type;  
};                       
 
 
int g[JAADA][JAADA];       
int treee[JAADA];                                                         
int way[2][JAADA],endPath[2]; 
bool milna[JAADA]; 
Label label[JAADA]; 
elem Quu[2*JAADA];        
int QF,queueBack;  
 

void intialAlgorithm(int n){            
     QF=queueBack=0;    
     for (int i=0; i<n; i++){   
         treee[i]=i;
         label[i].even=label[i].odd[0]=label[i].odd[1]=undef;
     }
}
 
void backtrace (int vert, int pathNum, int stop, int parity, int direction){
     if (vert==stop) return;           
     else if (parity==0){              
        if (direction==reverse){
           backtrace(label[vert].even,pathNum,stop,(parity+1)%2,reverse);
           way[pathNum][endPath[pathNum]++]=vert;
        }                             
        else if (direction==aage){ 
             way[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].even,pathNum,stop,(parity+1)%2,aage);
        }
     }
     else if (parity==1 && label[vert].odd[1]==undef){
        if (direction==reverse){
           backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,reverse);
           way[pathNum][endPath[pathNum]++]=vert;
        }
        else if (direction==aage){
             way[pathNum][endPath[pathNum]++]=vert;
             backtrace(label[vert].odd[0],pathNum,stop,(parity+1)%2,aage);
        }
     }
     else if (parity==1 && label[vert].odd[1]!=undef){
          if (direction==reverse){
             backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,reverse);
             backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,aage);
             way[pathNum][endPath[pathNum]++]=vert;
          }
          else if (direction==aage){
               backtrace(label[vert].odd[1],pathNum,vert,(parity+1)%2,reverse);
               backtrace(label[vert].odd[0],pathNum,empty,(parity+1)%2,aage);
               way[pathNum][endPath[pathNum]++]=vert;
          }
     }
}
 
void enqueue (int vert, int t){
     elem tmp;               
     tmp.vertex=vert;       
     tmp.type=t;             
     Quu[queueBack++]=tmp; 
}
 
void OldFlower (int a, int b){     
     int i,base,innerBlossom,innerBase;
     for (i=0; way[0][i]==way[1][i]; i++);   
     i--;                                      
     base=treee[way[0][i]];                 
                                               
     for (int j=i; j<endPath[0]; j++) treee[way[0][j]]=base;
     for (int j=i+1; j<endPath[1]; j++) treee[way[1][j]]=base; 
     for (int p=0; p<2; p++){                                     
        for (int j=i+1; j<endPath[p]-1; j++){
            if (label[way[p][j]].even==undef){        
               label[way[p][j]].even=way[p][j+1];    
               enqueue(way[p][j],0);                  
            }
            else if (label[way[p][j]].odd[0]==undef && label[way[p][j+1]].even==undef){
                 label[way[p][j]].odd[0]=way[p][j+1];
                 enqueue(way[p][j],1);                 
            }                                           
           
            else if (label[way[p][j]].odd[0]==undef && label[way[p][j+1]].even!=undef){
                 innerBlossom=treee[way[p][j]];
                 innerBase=j;
                 for (; treee[j]==innerBlossom && j<endPath[p]-1; j++);
                 j--;
                 label[way[p][innerBase]].odd[0]=way[p][j+1];
                 label[way[p][innerBase]].odd[1]=way[p][j];
                 enqueue(way[p][innerBase],1);
            }
        }
     }
     if (g[a][b]==unmatched){           
        if (label[a].odd[0]==undef){    
           label[a].odd[0]=b;           
           enqueue(a,1);               
        }                              
        if (label[b].odd[0]==undef){
           label[b].odd[0]=a;
           enqueue(b,1);
        }                              
     }
     else if (g[a][b]==matched){
          if (label[a].even==undef){
             label[a].even=b;
             enqueue(a,0);
          }
          if (label[b].even==undef){
             label[b].even=a;
             enqueue(b,0);
          }
     }
}
 
void augmentPath (){          
     int a,b;               
     for (int p=0; p<2; p++){
         for (int i=0; i<endPath[p]-1; i++){
             a=way[p][i];             
             b=way[p][i+1];           
             if (g[a][b]==unmatched)   
                g[a][b]=g[b][a]=matched;
             else if (g[a][b]==matched)
                  g[a][b]=g[b][a]=unmatched;
         }
     }
     a=way[0][endPath[0]-1];
     b=way[1][endPath[1]-1];
     if (g[a][b]==unmatched) g[a][b]=g[b][a]=matched;
     else if (g[a][b]==matched) g[a][b]=g[b][a]=unmatched;
     milna[way[0][0]]=milna[way[1][0]]=true;
}
 void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
 
    printf ("Following activities are selected \n");
 
    // The first activity always gets selected
    i = 0;
    printf("%d ", i);
 
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or equal to the finish
      // time of previously selected activity, then select it
      if (s[j] >= f[i])
      {
          printf ("%d ", j);
          i = j;
      }
    }
}
 
bool AM (int n){  
     int node,nodeLabel;      
     intialAlgorithm(n);               
     for (int i=0; i<n; i++) if (!milna[i]){
         label[i].even=empty;
         enqueue(i,0);          
     }                          
     
     while (QF<queueBack){
         node=Quu[QF].vertex;
         nodeLabel=Quu[QF].type;
         if (nodeLabel==0){
            for (int i=0; i<n; i++) if (g[node][i]==unmatched){
                if (treee[node]==treee[i]);
                else if (label[i].even!=undef){
                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,empty,0,reverse);
                     backtrace(i,1,empty,0,reverse);
                     if (way[0][0]==way[1][0]) OldFlower(node,i);
                     else {
                          augmentPath();
                          return true;
                     }
                }
                else if (label[i].even==undef && label[i].odd[0]==undef){
                     label[i].odd[0]=node;
                     enqueue(i,1);
                }
            }
         }
         else if (nodeLabel==1){
            for (int i=0; i<n; i++) if (g[node][i]==matched){
                if (treee[node]==treee[i]);
                else if (label[i].odd[0]!=undef){
                     endPath[0]=endPath[1]=0;
                     backtrace(node,0,empty,1,reverse);
                     backtrace(i,1,empty,1,reverse);
                     if (way[0][0]==way[1][0]) OldFlower(node,i);
                     else {
                          augmentPath();
                          return true;
                     }
                }
                else if (label[i].even==undef && label[i].odd[0]==undef){
                     label[i].even=node;
                     enqueue(i,0);
                }
            }
         }
         QF++;
     }
     return false;
}
 
void FMM (int n){
     for (int i=0; i<n; i++) milna[i]=false;
     while (AM(n));
}
 
int main(){
	int t;
	cin>>t;
	while(t--){
    int n;
    //n=readGraph();
    	int e,a,b;
    	n=readInt();
    	e=readInt();    
     	for (int i=0; i<n; i++)
         for (int j=0; j<n; j++) 
		 	g[i][j]=0;
		              
     	for (int i=0; i<e; i++){  
		 	a=readInt();
			b=readInt();  
         	if (a!=b)
            g[a-1][b-1]=g[b-1][a-1]=unmatched;
     	}
     
    int mycount[110]={0};
    int x=0;
    FMM(n);
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++) if (g[i][j]==matched)
        {
            mycount[i+1]++;
            mycount[j+1]++;
    }
}
    
    for(int i=1;i<=n;i++)
    {
    	if(mycount[i]==1)
    	continue;
    	else
    	{
    		x=1;
    		break;
    	}
    	
    }
    if(x!=1)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
}
