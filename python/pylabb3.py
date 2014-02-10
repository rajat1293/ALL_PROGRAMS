principal = 10000 #initial investment
interestRate = 0.05
years = 20
values = []
for i in range(years + 1):
    values.append(principal)
    principal += principal*interestRate
pylab.plot(range(years+1), values,'ro',linewidth=21)# (to change color of line to red
# and 'o'to use dots instead of line)
pylab.title('5% Growth, Compounded Annually',fontsize=9 )
pylab.xlabel('Years of Compounding',fontsize=2)
pylab.ylabel('Value of Principal ($)',fontsize=6 )
pylab.show()
#the defalut color is blue and the default line is
#.rc file runtime configuration file make changes to the default values
#ANOTHER PROGRAM WITH THE MORTAGAGE IS LEFT.........
#TO THE ANOTHER ONE
