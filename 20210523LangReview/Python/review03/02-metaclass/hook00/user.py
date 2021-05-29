"#Python is a protocol orientated lang; every top-level function or syntax has a corresponding dunder method implemented;" 

from library import Base 

assert hasattr(Base, 'foo'), f'foo() not found in {Base}'

class Derived(Base):
    def bar(self):
        return self.foo()

class A(Base):
    def a(self):
        return 'a'