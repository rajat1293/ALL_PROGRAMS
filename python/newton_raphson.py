# Lecture 3.7, slide 3

# Newton-Raphson for square root

epsilon = 0.01
y = 12345.0
guess = y/2.0
iterations=0
while abs(guess*guess - y) >= epsilon:
    iterations+=1
    guess = guess - (((guess**2) - y)/(2*guess))
    print(guess)
print('Square root of ' + str(y) + ' is about ' + str(guess)+'in iterations'
      + str(iterations))
