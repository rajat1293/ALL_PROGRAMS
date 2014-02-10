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




class student(nit):
    pass

class  UG(student):
     def __init__(self,name,year):
        nit.__init__(self,name)
        self.year=year
     def gclass(self):
          return self.year
class grad(student):
    pass
class TransStudent(student):
    pass
def isStudent(obj):
        return isinstance(obj,student)
    
class grades(object):
    def __init__(self):
        #empty grade book
        self.students=[]
        self.grades={}
        self.issorted=True
    def addstudent(self,student):
        #add stu to grade book
        if student in self.students:
           raise ValueError('duplicate student')
        self.students.append(student)
        self.grades[student.getid()]=[]
        self.isSorted=False
    def addgrade(self,student,grade):
        try:
            self.grades[student.getid()].append(grade)#//////////////
        except KeyError:
                raise ValueError('student nit in the grade book')
    def getgrades(self,student):
        try:
            return self.grades[student.getid()]#//////////
        except KeyError:
            raise ValueError('student nit in the grade book')
    def allstu(self):
        if not self.issorted:
            self.students.sort()
            self.issorted=True
       # return self.students[:]
        for s in self.students:
          yield s
def gradereport(course):
        report=[]
        for s in course.allstu():
            tot=0.0
            numgrades=0
            for g in course.getgrades(s):
                tot += g
                numgrades += 1
            try:
                average=tot/numgrades
                report.append(str(s)+'\'s mean grade is '+str(average))
                              
            except ZeroDivisionError:
              report.append(str(s)+ 'has no grades')
        return '        '.join(report)#//////////
    
ug1=UG('rajat gambhir',2014)
ug2=UG('shobhit saxena',2015)
ug3=UG('vishal singla',2003)
g1=grad('pradeep joshi')
g2=grad('shivam jindal')

six00=grades()
six00.addstudent(g1)
six00.addstudent(ug2)
six00.addstudent(ug1)
six00.addstudent(g2)

for ss in six00.allstu():
  six00.addgrade(ss,75)
six00.addgrade(g1,25)
six00.addgrade(g2,100)

six00.addstudent(ug3)
# check the sorting sequence
    

