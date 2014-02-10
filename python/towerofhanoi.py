def tower(s,a,d,n):
  if(n==1):
   print(str(s)+'->'+str(d))
  else:
     tower(s,d,a,n-1)
     tower(s,a,d,1)
     tower(a,s,d,n-1)
     
  
