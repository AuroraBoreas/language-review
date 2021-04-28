"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"""
[ metaclass ]
===
* take a minute to recall type structure in C#
* just like all other types are derived from System.Object;

* similarly, all other types are derived from type in Python;

===

"""

class BaseMeta(type):
    def __new__(cls, name, bases, body):
        print('__new__ : ', cls, name, bases, body)
        # here we may intercept the process and insert our logic
        # here we go brr
        if bases: # some classes does not have base class;
            assert 'bar' in body, "bar() method not found in user classes!"
        return super().__new__(cls, name, bases, body)

class Base(metaclass=BaseMeta):
    def foo(self):
        return self.bar()
