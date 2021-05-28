/*

this module is to demonstrate interface concept in Swift

@ZL, 20210526

[ conclusion ]
===
- JavaScript does support interface, alias `protocol`
===

*/

import cocoa
import UIKit

protocol Pack {
    func start() -> String
}

class Carton: Pack {
    var m_name: String
    var m_age: Int

    init(_ name: String, _ age: Int) {
        self.m_name = name
        self.m_age = age
    }

    override func start() -> String{
        return "class Carton says hello"
    }
}

let c: Carton = Carton("TS", 30)
print(c.start())