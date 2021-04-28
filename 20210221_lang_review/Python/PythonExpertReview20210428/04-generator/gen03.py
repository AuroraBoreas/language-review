"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"""
[ yield ]
===
* return evaluation result;
* return control to caller;

-- pattern
* interleaving
* sequencing

===

"""

import time

def compute(n: int)->int:
    for i in range(n):
        yield i
        time.sleep(.5)

class API:
    def func1(self):
        print('func1')

    def func2(self):
        print('func2')

    def func3(self):
        print('func3')

    def func4(self):
        print('func4')

    def __call__(self):
        self.func1()
        yield
        self.func2()
        yield
        self.func3()
        yield
        self.func4()
        
if __name__ == '__main__':
    # for i in compute(10):
    #     print(i)

    # interleaving and sequencing
    api = API()
    for f in api():
        print("contol in main")