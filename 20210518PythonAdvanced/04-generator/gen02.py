"#Python is a protocol orientated lang; every top-level function or syntax has a corresponding dunder method implemtned;" 

import time

class Compute:
    def __init__(self, last: int):
        self.last  = last
        self.first = 0

    def __enter__(self):
        return self

    def __next__(self):
        rv = self.first
        self.first += 1
        time.sleep(.5)
        if self.first > self.last:
            raise StopIteration()
        return rv

if __name__ == "__main__":
    for i in Compute(10):
        print(i)