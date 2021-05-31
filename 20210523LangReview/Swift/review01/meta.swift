/*
Swift meta review

@ZL, 20210531
*/ 

import UIKit

public enum Lib {
    func variableDemo() -> Void {
        /*
        @ variable
        ===
        - concept: box
        - pattern: TNV
        - feature:
            $ primitive types
                ~ CSIL FD BBD

            $ type traits
            $ type conversion
                ~ downcasting, upcasting
                ~ implicit, explicit
                
            $ variable template
            $ initialization
                ~ early binding, late binding
                ~ resouce acquisition is list initialization
                ~ narrowing
                ~ initialization methods
                    % T varName = Val;
                    % T varName(Val);
                    % T varName{Val};
                    % T varName = T(Val);
                    % T varName = T{Val};

            $ Val, Ref, Pointer
                ~ ByVal
                    % primitive types, string, enum, struct
                    % class, object

                ~ ByRef
                ~ ByPtr

            $ optional T
                ~ concept: is similar with Nullable in C#
                ~ pattern: var varName: T?
                ~ feature:
                    % w/o initialization, by default, varName is assigned with `nil`
                    % after initialization, varName is assigned with Val
                    % unwrapping, optional binding, force unwrapping, optional chaining
                        & unwrapping: `if varName != nil { ... }`
                        & optional binding: `if let my_varName = varName { ... }` or using `var` instead of `let`
                        & force unwrapping: `let my_varName = varName!`
                    
                    % positions
                        & position of ? matters, especially when using optional chaining
                        & position of ! matters, before varName, it's logical operator; after varName, it's force unwrapping operator
                    
                    % optional chaining
                        & let my_varName = varName ?? "OK" : "NG"

            $ keywords
                ~ var
                ~ let
        ===
        */ 

        var x0: Int; x0 = 69
        let x1: Double = 2.7182818
        x1 = 3.14 // error out
        let x2: Int = (Int)x1
        let x3: Bool = true
        let x4: Float = 1 // implicit type conversion
        // interpolation
        print("x0 = \(x0), type : \(type(of: x0))")
        print("x1 = \(x1), type : \(type(of: x1))")
        print("x2 = \(x2), type : \(type(of: x2))")
        print("x3 = \(x3), type : \(type(of: x3))")
        print("x4 = \(x4), type : \(type(of: x4))")
    }

    func functionDemo() -> Void {
        /*
        @ function
        ===
        - concept: black box
        - pattern: TNP
        - feature:
            ~ regular
            ~ [x]anonymous
            ~ [x]lambda
            ~ immediate
            ~ closure
                % { (args: T) -> U in return  }

            ~ [x]function pointer
            ~ [x]delegate
            
            ~ [x]decorator, but Swift provides a wrapper functionality
            ~ [x]generator
            
            ~ nested function
            ~ nested class in function

            ~ return_type
                % ByVal, ByRef, ByPtr

            ~ function name
                % overload
                % override
            
            ~ args
                % ByVal, ByRef, ByPtr
                % [x]params
                % in, out, ref
        ===        
        */ 

        func fibonacci(_ n: Int) -> Int {
            return n < 2 ? 1 : fibonacci(n-1) + fibonacci(n-2)
        }

        func factorial(_ n: Int) -> Int {
            return n < 2 ? 1 : n * factorial(n-1)
        }

        print("fibonacci(5) : \(fibonacci(5))")
        print("factorial(5) : \(factorial(5))")

        let f1: (Float) -> Float = {
            (x: Float) -> Float in
            return x * 2
        }
        print("lambda, f1(5) : \(f1(5.0))")

        func average(arr: [Int]) -> () {
            func calc(arr: [Int]) -> Double {
                var total: Int = 0
                for elem in arr {
                    total += elem
                }

                return (Double)total / arr.count
            }
            print("average of \(arr) : \(calc(arr))")
        }
        average([1, 2, 3])

        func hello(wife name: String, herAge age: Int) -> String {
            class Wife {
                var m_name: String?
                var m_age : Int?
                init(_ name: String, _ age: Int) {
                    self.m_name = name
                    self.m_age = age
                }
                func toString() -> String {
                    return "\nname: \(self.m_name)\nage: \(self.m_age)"
                }
            }
            return Wife(name, age).toString()
        }
        print("nested class in function : \(hello("TS", 30))")
    }

    func statementDemo() -> Void {
        /*
        @ statement
        ===
        - concept: link
        - pattern: link
        - feature:
            ~ Arithmetic
                % +, -, *, /, %
                % ++, --; ++, --

            ~ Relational
                % ==, !=
                % >, >=
                % <. <=

            ~ Logical
                % !
                % &&
                % ||

            ~ Access
                % .

            ~ Bitwise
                % <<, >>
                % ~
                % &
                % |

            ~ Assign
                % =

            ~ Cast
                % [x]dynamic_cast<T*>(U*)
                % [x]static_cast<T>(U)
                % [x]const_cast<T>(U)
                % [x]reinterpret_cast<T>(U)
                % (C-style)T

            ~ Op for storage
                % [x]new
                % [x]delete

            ~ Op for other
                % ()
                % []
                % {}
                % <>
                % @
                % &
                % ??
        ===
        */ 
        let x: Int = 69, y: Int = 42
        // a
        print("x = \(x), y = \(y); x + y : \(x + y)")
        print("x = \(x), y = \(y); x - y : \(x - y)")
        print("x = \(x), y = \(y); x * y : \(x * y)")
        print("x = \(x), y = \(y); x / y : \(x / y)")
        print("x = \(x), y = \(y); x % y : \(x % y)")

        // r
        print("x = \(x), y = \(y); x == y : \(x == y)")
        print("x = \(x), y = \(y); x != y : \(x != y)")
        print("x = \(x), y = \(y); x > y : \(x > y)")
        print("x = \(x), y = \(y); x >= y : \(x >= y)")
        print("x = \(x), y = \(y); x < y : \(x < y)")
        print("x = \(x), y = \(y); x <= y : \(x <= y)")
        
        // l
        print("x = \(x), y = \(y); !x : \(!(!x))") // error out
        print("x = \(x), y = \(y); x && y : \(x && y)") // error out
        print("x = \(x), y = \(y); x || y : \(x || y)") // error out
        
        // a
        struct Point {
            var x: Int = 0
            var y: Int = 0

            init(x: Int, y: Int) {
                self.x = x; self.y = y;
            }

            mutating func toString() -> String {
                return "Point[\(x), \(y)]"
            }
        }
        let p1: Point = Point(1, 1)
        print(p1.toString())

        // b
        var x1: Int
        x1 = x << 2
        print("x = \(x), y = \(y); x << 2 : \(x1)")
        x1 = x >> 2
        print("x = \(x), y = \(y); x >> 2 : \(x1)")
        print("x = \(x), y = \(y); ~x : \(~x)")
        print("x = \(x), y = \(y); x & y : \(x & y)")
        print("x = \(x), y = \(y); x | y : \(x | y)")

        // a
        x1 = 42
        print("assignment operator, x1 = \(x1)")
    }

    func controlflowDemo() -> Void {
        /*
        @ controlflow
        ===
        - concept: branch
        - pattern: branch
        - feature:
            ~ if...else if...else..
            ~ switch...case...default
            ~ do { try? } catch(...) { ... } catch { ... } 
        ===
        */ 
        
        func isLeapYear(_ year: Int) -> Bool {
            return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
        }

        func setDate(_ y: Int, _ m: Int, _ d: Int) -> Bool {
            if y < 0 { return false }
            if m < 0 || m > 12 { return false }
            if d < 0 || d > 31 { return false }
            switch m {
            case 2:
                if isLeapYear(y) {
                    if d > 29 { return false }
                } else {
                    if d > 28 { return false }
                }
                break
            case 4, 6, 9, 11:
                if d > 30 { return false }
                break
            default:
                print("do nothing")
                break
            }
            return true
        }
        print("setDate(2021, 2, 29) is legal? : \(setDate(2021, 2, 29))")
        
        func divisionByZero(_ a: Int, _ b: Int) throws -> Double {
            return (Double) a / b
        }

        do {
            try divisionByZero(10, 0)
        } catch {
            print("Arithmetic Error: can not divided by zero!")
        }
    }

    func loopDemo() -> Void {
        /*
        @ loop
        ===
        - concept: circle
        - pattern: circle
        - feature:
            ~ for(;;)
            ~ for...in...
            ~ while
            ~ repeat...while
        ===
        */

        let numbers: Array<Int> = Array<Int>(repeating: [1, 2, 3], count: 5)
        for(int i=0; i < numbers.count; ++i) {
            print("\(i), \(numbers[i])", separator: " ")
        }
        print()

        for elem in numbers {
            print(elem, separator: " ")
        }
        print()

        let i: Int = 0
        while i < numbers.count {
            print("\(i), \(numbers[i])", separator: " ")
            i++
        }
        print()

        i = numbers.count - 1
        repeat {
            print("\(i), \(numbers[i])", separator: " ")
            --i
        } while (i >= 0)

        numbers.forEach { elem in 
            print(elem, separator: " ")
        }

        // range: start...stop where predict
        // stride: stride<T>(start, stop, step)
    }

    func classDemo() -> Void {
        /*
        @ class
        ===
        - concept: sim
        - pattern: sim
        - feature:
            ~ Abstraction
            ~ Encapsulation
                $ getter and setter
                $ similar concepts in C#

            ~ Inheritance
                $ subclass inherits everything from Base class, including ctors; just like Pyton/JavaScript;
                $ multiple inheritance is not supported

            ~ Polymorphism
                $ override

        - oo principles:
            ~ SRP
            ~ OCP
            ~ LSP
            ~ ISP
            ~ DIP
        
        - keywords:
            ~ init
            ~ convenience (ctor delegation, master ctor, "funnel")
            
            ~ override
            ~ subscript

            ~ private
            ~ public
            ~ final

            ~ static
        ===
        */ 
        
        final class Point {
            private m_x: Int
            private m_y: Int
            static var n: Int = 0

            init() {
                m_x = 0
                m_y = 0
                n++
            }
            
            init(_ x: Int, _ y: Int) {
                m_x = x
                m_y = y
                n++
            }

            convenience init(_ x: Int) {
                self.init(x: x, y: 0)
            }

            convenience init(_ y: Int) {
                self.init(x: 0, y: y)
            }

            deinit {
                print("object Point(\(self.n--)) is destoryed!")
            }

            var x: Int {
                get { return self.m_x }
                set(newValue) { self.m_x = newValue}
            }

            var y: Int {
                get { return self.m_y }
                set { self.m_y = newValue }
            }

            public static Count() -> Int {
                return self.n
            }

            public func toString() -> String {
                return "Point[\(self.x), \(self.y)]"
            }
        }

        let p1: Point = Point(0, 0)
        print(p1.toString())

        class Base {
            var x: Int
            var y: Int
            init(_ x: Int, _ y: Int) {
                x = x
                y = y
            }
        }

        class Derived: Base {} 

        let d1: Derived = Derived(1, 1) // OK
        print(d1.x, d1.y) 
    }

    func protocolDemo() -> Void {
        /*
        @ protocol
        ===
        - concept: abstract a certain same behavior from classes
        - pattern: sim
        - feature:
            ~ it is similar concept like interface in C#, Java
            ~ interface can support classes to achieve same effect like "multiple inheritance"

            ~ works with "opque types"
        ===
        */

        protocol Prey {
            static func flee() -> Void
        }

        protocol Predator {
            static func hunt() -> Void
        }

        class Fish: Prey, Predator {
            func flee() -> Void {
                print("big fish inc! *fish* is fleeing")
            }

            func hunt() -> Void {
                print("small fish is delicious!")
            }
        }
        
        let fish1: Fish = Fish();
        fish1.flee()
        fish1.hunt()

        // generic: T is determined by "caller" using function interface
        func add<T>(_ a: T, _ b: T) -> T {
            return a + b
        }

        print("generic, add(3, 4): \(add(3, 4))")

        /* 
        @ opaque
        ===
        - concept: a concrete T is determined by "callee" using function interface
            $ "concrete" means the function return the same type per call
        - patter:
            $ `func funcName(args: T...) -> some Protocol { ... }`
        - opaque vs generic
        - opaque works with protocols
        ===
        */
        protocol P {}
        extension String: P {}
        extension Int: P {}

        func opaque() -> some P {
            return "1"
        }

        func opaque2(_ isInt: Bool) -> P {
            return isInt ? 1 : "1"
        }

        // ! but function can't return builtin protocol directly
        func opaque3() -> Equatable { 3 } // error out
    }

    func extensionDemo() -> Void {
        /*
        @ extension
        ===
        - concept: extends functionalities of an existed Type
        - pattern: just like extension method in C#
        - feature:
            ~ can not override existed functions of the Type
        ===
        */
        extension Double {
            var m: Double { return self }
            var cm: Double { return self / 100.0 }
            var mm: Double { return self / 1_000.0 }
            var km: Double { return self * 1_000.0 }            
        }

        let oneKm = 25.4.km
        print("one kilometer is \(oneKm) meters")
    }

    func datastructureDemo() -> Void {
        /*
        @ data structure
        ===
        - concept: container
        - pattern: container
        - feature:
            ~ seq
                % array
                % list
                % forward_list
                % vector
                % dequeue

            ~ adaptor
                % stack
                % queue
                % priority_queue

            ~ associative
                % map
                % multimap
                % set
                % multiset
                % unordered_map
                % unordered_set
                % unordered_multimap
                % unordered_multiset
        ===
        */

        let numbers: [Int] = [Int]() // array
        numbers.append(1)
        numbers.append(2)
        numbers.append(3)
        print(numbers)

        let wifes = Set<String>() // set
        wifes.insert("TS")
        wifes.insert("SCY")
        wifes.insert("LL")
        print(wifes)

        let friends = [String: Int]() // map
        friends["TS"] = 30
        friends["SCY"] = 35
        print(friends)
    }

    func algorithmDemo() -> Void {
        /*
        integrated into datastructure in Swift
        @ algorithm
        ===
        - concept: calc
        - pattern: calc
        - feature:
            ~ iterator, const_iterator
            ~ capacity
            ~ access
            ~ modification
            ~ list observation
            ~ bucket
            ~ hash policy
        ===
        */         
    }
}
