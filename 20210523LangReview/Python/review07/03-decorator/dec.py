"#python is a protocol orientated lang; every top-level function or syntax has a corresponding dunder method implemented;" 

def fibonacci(n: int)->int:
    return 1 if n < 2 else fibonacci(n-1) + fibonacci(n-2)

def factorial(n: int)->int:
    return 1 if n < 2 else n * factorial(n-1)

import functools
import time

def timer(func):
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        start = time.perf_counter_ns()
        rv    = func(*args, **kwargs)
        end   = time.perf_counter_ns()
        print('time lapsed(ns):', end - start)
        return rv
    return wrapper

@timer
def myfib(n: int)->int:
    """my fibonacci

    :param n: [description]
    :type n: int
    :return: [description]
    :rtype: int
    """
    return fibonacci(n)

@timer
def myfact(n: int)->int:
    """my factorial

    :param n: [description]
    :type n: int
    :return: [description]
    :rtype: int
    """
    return factorial(n)

if __name__ == "__main__":
    rv2 = myfib(5)
    rv1 = myfact(5)