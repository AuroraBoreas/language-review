"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

class Base:
    def foo(self):
        return 'foo'

"""
start point:

```Python

import dis

def func():
    class TS:
        def foo(self):
            return 'foo'

dis.dis(func)

>>> LOAD__BUILD_CLASS__
...
>>> CREATE_CLASS_OBJECT
...
>>> INIT_CLASS
...
>>> INVOKE_META_CLASS
...

```

flash point:

"""