"""
[ expriment result ]
===
- it turns out that Python suppurts ctor inheritance
===
"""

class Base:
    def __init__(self, x: int):
        self.x = x

class Derived(Base):
    pass

if __name__ == "__main__":
    d1: Derived = Derived(1)
    print(d1.x)