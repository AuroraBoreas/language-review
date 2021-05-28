"""

this module is to demonstrate interface concept in Python

@ZL, 20210526

[ conclusion ]
===
- Python does not support interface
- but it does have a walkaround, using class
===

"""

class Pack:
    def start(self):
        pass

class Carton(Pack):
    def __init__(self, *args):
        self.args = args
    
    def __repr__(self):
        return "Carton{!r}".format(self.args)

    def start(self):
        return "class Carton says hello"

if __name__ == "__main__":
    c: Carton = Carton("TS", 30)
    print(c)
    print(c.start())