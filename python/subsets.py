def genSubsets(L):
 res = []
 if len(L) == 0:
  return [[]] #list of empty list
 smaller = genSubsets(L[:-1])
 print("aa"+str(smaller))
 # get all subsets without last element
 extra = L[-1:]
 print("bb"+str(extra))
# create a list of just last element
 new = []
 for small in smaller:
   new.append(small+extra)
   print(new)
   #basically new contains a list of sublists
   #made by adding smmall and extra..
# for all smaller solutions, add one with last
 return smaller+new
# combine those with last element and those
