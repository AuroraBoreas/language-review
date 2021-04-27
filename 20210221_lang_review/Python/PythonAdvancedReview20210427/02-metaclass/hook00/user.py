"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

from library import Base

"""
context: 
normally, we import library and use APIs(classes, functions) w/o many worries;

Q: but in case of untouchable library, how do u guarantee that APIs have methods beforehand?
even know it before runtime?
A: hint -- using assert

"""

assert hasattr(Base, 'foo'), "foo method not found in Base class"

class Derived(Base):
    def bar(self):
        return self.foo()