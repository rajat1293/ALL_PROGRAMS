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
    
   
        
