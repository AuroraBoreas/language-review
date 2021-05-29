import UIKit

// @ opaque type vs generic
protocol P {}
extension Int: P {}
extension String: P {}

func opaqueFunc() -> some P { ... }
func genericFunc<T: P>() -> T { ... }

let a1 = opaqueFunc()
let a2 = opaqueFunc()
assert(a1 == a2, "otherwise u fucked up")   // OK

// @ opaque type works protocols
func myFunc1(_ isInt: Bool) -> P { isInt ? 1 : "1" } // OK
func myFunc2(_ isInt: Bool) -> some P { isInt ? 1 : "1"} // error out