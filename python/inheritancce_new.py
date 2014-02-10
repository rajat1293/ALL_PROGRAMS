import datetime


class  Person(object):
  def __init__(self,name):
   self.name=name
   self.bir=None
   self.las=name.split(' ')[-1]
  def getLN(self):
      return self.las
  def setbir(self,month,d,y):
      self.bir =datetime.date(y,month,d)
  def age(self):
      if self.bir==None:
       raise ValueError
      return (datetime.date.today()-self.bir).days

  def __lt__(self,other):
       """returns true if nae is dictionary wise first"""
       if self.las==other.las:
            return self.name<other.name
       return self.las<other.las
  def __str__(self):
       return self.name
    #See section 3.4 of the Python Language Reference for a
#list of other special methods
    
   
        





class nit(Person):
    nextid=0#shard variable
    def __init__(self,name):
        Person.__init__(self,name)
        self.id=nit.nextid#instance variable
        nit.nextid+=1


    def getid(self):
        return self.id
    def __lt__(self,other):
        return self.id<other.id

    """plistt=[p2,p1,p3]
>>> for p in plistt:
	print p

	
shibhit
rajat
jindla
>>> plistt.sort()
>>> for p in plistt:
	print p"""
    #this represents how the sort function internally uses the lt__
    #we defined to sort
    #another thing is the p4<p1 works well but not p1<p4
    #this is because the first one calls its routinr of leess which the
    #p1 inherits put secondd one calllls the routine of the latter and hence
    #error occrs







    
