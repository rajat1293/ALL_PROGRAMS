def selecsort(L):
    for i in range(len(L)):
      index=i
      small=L[i]
      j=i+1
      while j<len(L):
        if (L[j]<small):
            small=L[j]
            index=j
            print L
        j+=1
      tmp=L[index]
      L[index]=L[i]
      L[i]=tmp
    print L
