"#Python is a protocol orientated lang; every top-level function or syntax has a corresponding dunder method implemtned;" 

class Polynomial:
    def __init__(self, *args):
        self.args = args

    def __repr__(self):
        return "Polynomial{!r}".format(self.args)

    def __add__(self, other):
        return Polynomial(*(x + y for x, y in zip(self.args, other.args)))

    def __sub__(self, other):
        return Polynomial(*(x - y for x, y in zip(self.args, other.args)))

    def __call__(self):
        return 'u call i come'

if __name__ == "__main__":
    p1: Polynomial = Polynomial(1, 2, 3)
    p2: Polynomial = Polynomial(1, 2, 3)
    print(p1 + p2)