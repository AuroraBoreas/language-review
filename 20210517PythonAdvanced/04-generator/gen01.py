"#Python is a protocol orienated lang; every top-level function or syntax has a corresponding duner method implemented;" 

import time

def compute(n: int)->list:
    rv = list()
    for i in range(n):
        rv.append(i)
        time.sleep(.5)
    return rv

if __name__ == "__main__":
    for i in compute(10):
        print(i)