"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 


"""
[ context ]
===
* image that u are in user.py
* u can NOT modify or contact the person who create or maintain library.py

Q: how do user guarantee that library class has foo() method in the first place?
even before runtime?

A: using assert

===

"""
from library import Base

assert hasattr(Base, 'foo'), "foo() method not found in Base class"

class Derived(Base):
    def bar(self):
        return self.foo()