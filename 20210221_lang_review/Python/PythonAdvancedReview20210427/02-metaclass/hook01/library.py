"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"""

[ untouchable user class ]
===
Q: how to ensure that user classes have implemented certain functions like bar?
even know it before runtime?

A: we must be familiar with class construction process by Pyton compiler; 
it turns out there are three points where we can intercept class construction process:

* "BBC"
* metaclass
* __init__subclass__

===

"""

class Base:
    def foo(self):
        return self.bar()

old_bc = __build_class__

def my_bc(*args, **kwargs):
    print('__build_class__ ->', args, kwargs)
    return old_bc(*args, **kwargs)

import builtins
builtins.__build_class__ = my_bc


