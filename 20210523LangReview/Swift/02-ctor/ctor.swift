import cocoa

class Base {
    var m_x: Int
    init(_ x: Int) {
        m_x = x
    }
    init?(_ symbol: Character) {
        switch symbol {
            case "K":
                self.m_x = 0
            case "C":
                self.m_x = 1
            case "F":
                self.m_x = 2
            default:
                return nil
        }
    }
    
    deinit {
        // pass
    }
    
}

class Derived: Base {

}

let d1: Derived = Derived(1) // OK
print(d1.m_x)