"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented" 

import time

class Compute:
    def __init__(self, n):
        self.last = 0
        self.n = n

    def __iter__(self):
        # self.last = 0
        return self
    
    def __next__(self):
        rv = self.last
        self.last += 1
        time.sleep(.5)
        if self.last > self.n:
            raise StopIteration()
        return rv


if __name__ == '__main__':
    for i in Compute(10):
        print(i)