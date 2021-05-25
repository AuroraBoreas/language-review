/*

a simple module demonstrates closure mechnsim in Swift

@ZL, 20210525

[ experiment result ]
~ by default, Swift allows inner scope to read the object in outer scope
~ Swift does allow re-binding or write an object in outer scope

*/

import cocoa
import UIKit

func outer(_ n: Int) -> () -> Int {
    var total: Int = 0
    func inner() -> Int {
        total += n
        return total
    }
    return inner
}

let f = outer(10)

print("1st call, \(f())")
print("2nd call, \(f())")
print("3rd call, \(f())")
