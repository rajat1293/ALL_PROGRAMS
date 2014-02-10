L1=[1,2,3,4]
L2=[5,6,1,2]
#def removeDups(L1, L2):
L2start=L1[:]
for e1 in L2start:
  if e1 in L2:
   L1.remove(e1)
print(L1)
