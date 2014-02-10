def applyFuns(L, x):
 for f in L:
  print(f(x))
  
def fact(n):
    if n == 1:
        return 1
    else:
        return n*fact(n-1)
    
def fib(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)
applyFuns([abs, int, fact, fib], 4)
