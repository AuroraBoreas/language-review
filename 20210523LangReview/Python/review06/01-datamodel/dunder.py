"#Python is a protocol orientated lang; every top-level function or syntax has a corresponding dunder method implemented;" 

import itertools

class Polynomial:
    def __init__(self, *args):
        self.args = args

    def __repr__(self):
        return "Polynomial{!r}".format(self.args)

    def __call__(self):
        return "U call I come"

    def __add__(self, other):
        return Polynomial(*(x + y for x, y in itertools.zip_longest(self.args, other.args)))

if __name__ == "__main__":
    p1: Polynomial = Polynomial(1, 2, 3)
    p2: Polynomial = Polynomial(4, 5, 6)
    print(p1 + p2)

