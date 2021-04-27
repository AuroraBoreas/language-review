"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 

"""
Q: what if u wanna meas the performance of user functions?
A: rewrite the functions? but sometimes functions from libraries are not rewriteable;

Q: any thoughts?
A: using 

"""
import time

# wrapper
def timer(func):
    def wrapper(*args, **kwargs):
        start = time.perf_counter()
        rv    = func(*args, **kwargs)
        end   = time.perf_counter()
        print('{0.__name__} elapsed: {1}s'.format(func, end - start))
        return rv
    return wrapper

def repeater(n=2):
    def dec(func):
        def inner(*args, **kwargs):
            for _ in range(n):
                print(func(*args, **kwargs))
        return inner
    return dec

# @repeater(n=2) # error out
@timer
def fibonacci(n: int)->int:
    return 1 if n < 2 else fibonacci(n-1) + fibonacci(n-2);

# @repeater(n=3) # error out
@timer
def factorial(n: int)->int:
    return 1 if n < 2 else n * factorial(n-1);

# sometimes, it is not smooth process :)
# solution: using another function to wrap user recursive functions to avoid potential problems

@repeater()
def myfibonacci(n: int)->int:
    return fibonacci(n)

@repeater(n=3)
def myfactorial(n: int)->int:
    return factorial(n)


if __name__ == '__main__':
    # print(fibonacci(5))
    # print(factorial(4))

    # after wrapping?
    myfactorial(5)
    myfactorial(4)