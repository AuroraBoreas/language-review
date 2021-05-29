import cocoa

class Base {
    var x: Int = 0
    init(_ x: Int) {
        self.x = x
    }
}

// ^ convenience is just Swift implementation of ctor delegation in C#, C++ etc;
class Derived: Base {
    var y: Int
    
    int(_ x: Int, _ y: Int) {
        super.init(x)
        self.y = y
    }

    convenience init(_ x: Int) {
        self.init(x: x, y:0)
    }

    convenience init() {
        self.init(x: 0, y: 0)
    }

    convenience init(_ y: int) {
        self.init(x: 0, y: y)
    }
}
