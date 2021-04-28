"# python is a protocol orientated lang; every top-level function has a corresponding dunder method implemented;" 


class Base:
    def foo(self):
        return self.bar()

    def __init_subclass__(cls, *args, **kwargs):
        print('__init_subclass__ : ', cls, args, kwargs)
        # we may intercept and insert our logic here
        assert hasattr(cls, 'bar'), "bar() method not found in user class!"
        return super().__init_subclass__()