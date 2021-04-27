"# python is a protocol orientated lang; every top-level function has a corresponding dunder method;"

class Polynomial:
    def __init__(self, *args):
        self.args = args
    
    def __repr__(self):
        return "Polynomial{!r}".format(self.args)

    def __add__(self, other):
        return Polynomial(*(x + y for x, y in zip(self.args, other.args)))
    
if __name__ == '__main__':
    p1 = Polynomial(1, 3, 4)
    p2 = Polynomial(2, 3, 5)
    print(p1)
    print(p1 + p2)