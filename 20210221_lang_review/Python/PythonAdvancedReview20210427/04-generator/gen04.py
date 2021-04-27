"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

import time

"""
[ yield ]
===
there are mainly two effects when using "yield" kw
* return evaluation result;
* return control and handler it over to main;

* note:
it is important to memorize that "yield" is sequencing!

this means, its behavior is like interleaving;

===
"""

class API:
    def func1(self):
        print("func1")

    def func2(self):
        print("func2")

    def func3(self):
        print("func3")

    def func4(self):
        print("func4")

    def __call__(self):
        self.func1()
        yield
        self.func2()
        yield
        self.func3()
        yield
        self.func4()


if __name__ == '__main__':
    api = API()
    for f in api():
        print('control in main')
        f
