#include<stdio.h> 
int main() { 
// printf("%d %d", comb(6,2),power (2,3)); 
long long p,q,r,s,t,u,v,N,A,B,C,T, S,l,k;
 scanf("%lld",&T);
  while(T--) {
   S=0; 
   scanf("%lld%lld%lld%lld",&N,&A,&B,&C); 
   p=A+1;q=B+1;r=C +1;
   s=A+B+2;t=B+C +2;
   u=A+C+2;v=A+B +C+3; 
   for(k=0;k<=N;k++) { 
   l=N-k; S=S+(l+2)*(l+1) /2;
    if(l-p>=0) S=S-(l-p+2)*(l-p +1)/2; 
	if(l-q>=0) S=S-(l-q+2)*(l-q +1)/2; 
	if(l-r>=0) S=S-(l-r+2)*(l-r +1)/2; 
	if(l-s>=0) S=S+(l-s+2)*(l-s +1)/2; 
	if(l-t>=0) S=S+(l-t+2)*(l-t +1)/2;
	 if(l-u>=0) S=S+(l-u+2)*(l-u +1)/2;
	  if(l-v>=0) S=S-(l-v+2)*(l-v +1)/2; 
	  }
	   printf("%lld\n",S) ;
	   }
	    return 0; }
