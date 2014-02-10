L1=[1,2,3,4]
L2=[5,6,1,2]
#def removeDups(L1, L2):
for e1 in L1:
  if e1 in L2:
   L1.remove(e1)
print(L1)
#thhis prints wroong because python does not update the pointer
#every time 1 now means that 3 not 2 so we need to copy
