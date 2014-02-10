x=int(raw_input('enter a value to cal root of'))
y=float(raw_input('enter a guess '))
while True:
    if(abs(y*y-x)<=0.001):
     print('the root of '+ str(x)  + 'is' +  str(y))
     break
    else:
     y=(y+x/y)/2
    
