def recurmul(a,b):
 if b==1:
    return a
 else:
    return a+recurmul(a,b-1)

