def iterativePower(x, p):
    result = 1
    for turn in range(p):
       print ('iteration: ' +
       str(turn) + ' current result: '
       + str(result))
       result = result * x
    return result

x = float(raw_input('Enter a number: '))
p = int(raw_input('Enter an integer power: '))
result = 1
for turn in range(p): 
  print('iteration: ' + str(turn) + \
  'current result: ' + str(result))
  result = result * x
  z=iterativePower(5,4)
print(str(z))


