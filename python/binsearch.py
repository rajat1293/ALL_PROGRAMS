def bisearch(l,f):
  low=0
  high=len(l)-1
  def bsear(l,f,low,high):
    if(low>high):
        return False
    mid=(int)(low+high)/2
    if l[mid]==f:
     return mid
    elif l[mid]<f:
        return bsear(l,f,mid+1,high)
    else:
       return bsear(l,f,low,mid-1)
  return bsear(l,f,low,high)  
      
