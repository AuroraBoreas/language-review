"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"""
[ caution ]
===
* recursion functions
* NoneType exceptions
* why
* solution
===

[ TODOS ]
===
* meas performance
* repeat N times
===

"""

import time

def timer(func):
    def wrapper(*args, **kwargs):
        start = time.perf_counter()
        rv    = func(*args, **kwargs)
        end   = time.perf_counter()
        print("{.__name__}, elapsed time(s): {}".format(func, end - start))
        return rv
    return wrapper

def repeater(n=2):
    def dec(func):
        def wrapper(*args, **kwargs):
            for _ in range(n):
                print(func(*args, **kwargs))
        return wrapper
    return dec

# @timer
@timer
def fibonacci(n: int)->int:
    return 1 if n < 2 else fibonacci(n-1) + fibonacci(n-2)

@timer
def factorial(n: int)->int:
    return 1 if n < 2 else n * factorial(n-1)

# directly decorating recursivce functions may error out;
# for example above
# solution
@repeater()
def my_fibonacci(n: int)->int:
    return fibonacci(n)
@repeater()
def my_factorial(n: int)->int:
    return factorial(n)

if __name__ == '__main__':
    print("\n=== timer === ")
    print(fibonacci(5)) # 8
    print(factorial(5)) # 120

    # repeater
    print("\n=== repeater === ")
    my_fibonacci(5)
    my_factorial(5)