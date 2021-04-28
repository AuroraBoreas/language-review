"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"""
[ context ]
===
* given that u are in library.py
* u can NOT touch code in user.py

Q: how do u make sure that user class has bar() method in the first place?
even before runtime?
A: there are three approaches

- "BBC"
- metaclass
- __init_subclass__


Q: wait, how do u know these three methods?
A: using the following dummy code to see how Python compiler creates classes and functions; 

```Python

import dis

def func():
    class TS:
        def foo(self):
            return 'foo'

dis.dis(func)

```

result in console as follows.
we may see the pattern from these bytecode;
* classes in Python are live things; they are executable;
* after class definition in stack, compiler calls "BBC" first to create code object in memory;
* after the creation, compiler invokes metaclass to __new__ initiate one instance of the code object;

=> after scrutinize the class construction process by Python compiler,
=> we may have a good chance to intercept into the process and plant our logic inside; 

```Console

>>> import dis
>>> def func():
...     class TS:
...             def foo(self):
...                     return 'foo'
...
>>> dis.dis(func)
  2           0 LOAD_BUILD_CLASS
              2 LOAD_CONST               1 (<code object TS at 0x04C5EEE8, file "<console>", line 2>)
              4 LOAD_CONST               2 ('TS')
              6 MAKE_FUNCTION            0
              8 LOAD_CONST               2 ('TS')
             10 CALL_FUNCTION            2
             12 STORE_FAST               0 (TS)
             14 LOAD_CONST               0 (None)
             16 RETURN_VALUE

Disassembly of <code object TS at 0x04C5EEE8, file "<console>", line 2>:
  2           0 LOAD_NAME                0 (__name__)
              2 STORE_NAME               1 (__module__)
              4 LOAD_CONST               0 ('func.<locals>.TS')
              6 STORE_NAME               2 (__qualname__)

  3           8 LOAD_CONST               1 (<code object foo at 0x04C5EF40, file "<console>", line 3>)
             10 LOAD_CONST               2 ('func.<locals>.TS.foo')
             12 MAKE_FUNCTION            0
             14 STORE_NAME               3 (foo)
             16 LOAD_CONST               3 (None)
             18 RETURN_VALUE

Disassembly of <code object foo at 0x04C5EF40, file "<console>", line 3>:
  4           0 LOAD_CONST               1 ('foo')
              2 RETURN_VALUE
>>>

```


===

"""

class Base:
    def foo(self):
        return self.bar()


old_bc = __build_class__ # this builtin function will capture the original args of class;

def my_bc(*args, **kwargs):
    print('__build_class__ : ', args, kwargs)
    # we may intercept and insert our logic here
    return old_bc(*args, **kwargs)

import builtins
builtins.__build_class__ = my_bc # swap

