class intSet(object):
    """an intset is a set of integers
    the value is represented by a list of ints,self.vals.
    Each int in the set occurs in the self,vals exactly once ,"""
    def __init__(self):
        """create an empty set of integers"""
        self.vals=[]
    def insert (self,e):
        """assumes e is an integer and inserts e into self"""
        if not e in self.vals:
            self.vals.append(e)

    def member(self,e):
        """returns true if in there """
        return e in self.vals
    def remove (self,e):
        try:
            self.vals.remove(e)
        except:
            raise ValueError(str(e)+' not found')



    def __str__(self):
        """return string representation of self"""
        self.vals.sort()
        return '{' + ','.join([str(e) for e in self.vals])+'}'
    
