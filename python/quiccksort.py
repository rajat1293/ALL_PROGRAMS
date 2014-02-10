import operator
def partition(L,compare):
     i=-1
     j=0
     print ("aA"+str(len(L)))
     while j <(len(L)-1):
      print ("mm"+str(L[j])+str(L[-1])) 
      if compare(L[j],L[-1]):
         i+=1
         print L[i]
         print ("s"+str(i))
         tmp=L[i]
         L[i]=L[j]
         L[j]=tmp
      j+=1 
     k=L[i+1]
     L[i+1]=L[-1]
     L[-1]=k
     print("aaaaa")
     return i+1



def Quicksort(L,compare=operator.lt):
  if len(L)>=2:
    q=(int)(partition(L,compare))
    Quicksort(L[:q],compare)
    Quicksort(L[q+1:],compare)
  print L 
