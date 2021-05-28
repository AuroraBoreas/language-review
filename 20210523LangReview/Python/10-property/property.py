"""
Python 

@poperty

@classmethod
@staticmethod
>> these two methods are accessible at class-level
>> BUT, @staticmethod is immutable via inheritance
>> while, @classmethod is inheritable

"""

class Point:
    def __init__(self, a: int, b: int):
        self._a = a
        self._b = b

    # ^ simpler implementation of getter/setter in Python
    # ^ the concept under the hood is same with C#
    @property
    def center(self):
        return (self._a + self._b) / 2

    @classmethod
    def hello(cls):
        return "class Point says hello"
    
    @staticmethod
    def call():
        return "u call i come"

class Derived(Point):
    def normal_method(self):
        return "normal method"
    @classmethod
    def hello(cls):
        return "class Derived says hello"

    @staticmethod
    def call():
        return "class Derived says U call I come"

if __name__ == "__main__":
    p1: Point = Point(1, 2)
    print(p1.center)
    print(Point.hello())
    print(p1.call())
    print(Point.call())

    # $ test difference between classmethod vs staticmethod
    p2: Derived = Derived(2, 3)
    print(p2.call()) # % OK?
    print(p2.hello()) # % OK?