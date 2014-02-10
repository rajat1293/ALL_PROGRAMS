import pylab
pylab.figure(1)#make fig 1 the current fig
pylab.plot([1,2,3,4],[1,7,3,5])#draw fig1
pylab.figure(2)##make fig 2 the current fig
pylab.plot([1,4,2,3],[5,6,7,8])#draw fig 2
pylab.savefig('raj')#save fig2
pylab.figure(1)#make fig 1 the current fig
pylab.plot([5,6,10,3])#draw fig1
#we have not given another set of values
#the given set is that of the y values
#the x values are in the range(len(y values)] which
#here is [0,1,2,3]
pylab.savefig('rajat')#save fig1
#saved as raj.png
#portable networks graphics
