x=int(raw_input('enter  a number'))
y=abs(x)
res=''
if x<0:
 flag=1
else:
 flag=0
m=abs(x)
while m:
  r=m%2
  res = str(r)+res
  m=m/2
if(flag==1):
 res='-'+res
print('the binary form of result is' + res)
if y==0:
 print('0')

  
