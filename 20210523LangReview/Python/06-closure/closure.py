"""
a simple module demonstrates closure mechnsim in Python

@ZL, 20210525

[ experiment result ]
^ Python prevents this behavior (access local variable) by default
~ by default, Python allows inner scope to read the object in outer scope
~ but Python does not allow re-binding or write an object in outer scope

& To achieve the same behavior
using keyword `global` or `nonlocal` to re-bind the object in outer scope 

"""

def func(n: int):
    total = 0
    def inner():
        nonlocal total
        total += n
        return total
    return inner

if __name__ == "__main__":
    myfunc = func(10)
    print(myfunc())
    print(myfunc())
    print(myfunc())