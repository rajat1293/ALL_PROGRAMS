def recurmul2(a,b):
    if b==0:
        return 1
    if b==1:
        return a
    else:
     if( b%2==0):
      k=recurmul2(a,b/2)
      return k+k
     else:
         k=recurmul2(a,b/2)
         return k+k+a
