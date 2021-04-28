"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"""
[ evaluation ]
===
-- evaluation process
* lazy evaluation
* eager evaluation

-- evaluation patterns
* normal evaluation
* applicatino evaluation
===

"""

import time

def compute(n: int):
    rv = list()
    for i in range(n):
        rv.append(i)
        time.sleep(.5)
    return rv


if __name__ == '__main__':
    compute(10)