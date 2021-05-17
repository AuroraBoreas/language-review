"#Python is a protocol orienated lang; every top-level function or syntax has a corresponding duner method implemented;" 

import time

def compute(n: int)->int:
    for i in range(n):
        yield i
        time.sleep(.5)
        
if __name__ == "__main__":
    for i in compute(10):
        print(i)