/*

swift, meta review

@ZL, 20210524

*/ 

import cocoa
import UIKit

enum TS {
    
    public static void variableDemo()
    {
        /*
        @ variable
        ===
        * concept: box
        * pattern: TNV
        * feature:
            - primitive types(meta types)
                $ char
                $ short
                $ int
                $ long

                $ float
                $ double
                $ long double

                $ [x]byte
                $ boolean
                $ [x]decimal

            - type traits(reflect)
            - type conversion
                $ implicit vs explicit
                $ downcasting vs upcasting
                $ narrowing

            - initialization
                $ resource acquisition is initialization
                $ copy assignment operator
                $ copy ctor
                $ list initialization

            - ByVal, ByRef, ByPtr
                $ ByVal
                    ~ lvalue
                    ~ rvalue
                $ ByRef
                    ~ r-ref
                    ~ l-ref
                $ ByPtr
                    ~ raw pointer
                    ~ array
                    ~ smart pointer

            - variable template
                $ generic

            - keywords
                $ storage
                    ~ static
                    ~ const
                        % const and variable
                        % const and pointer
                        % const and function
                    ~ extern
                    ~ register
                    ~ auto
                
                $ compile time
                    ~ constexpr
                    ~ string literal

            - parameter vs argument
                $ argument means actual variable
                $ parameter means placeholder variable
        ===    
        */

        var x1: Int = 69
        let x2 = 2.718
        var x3: Bool? = false
        var x4: String! = "hello TS"
        
        print("x1 = \(x1)")
        print("x2 = \(x2)")
        print("x3 = \(x3!)")
        print("x4 = \(x4)")

        let y1: String? = "TS"
        let y2: String! = "ZL"

        if let myy1 = y1 {
            print(myy1)
        } else {
            print("nothing")
        }

        let y3: String = y2 ?? "Hoho"
        print(y3)

        let msg = """
        Id est sint irure dolor esse exercitation elit.
        Do deserunt cupidatat aliqua incididunt ex mollit laborum aliqua veniam.
        Irure amet aute ullamco id exercitation veniam aute.
        """
        print(msg)

        let raw = #"hello \(name)"#
        print(raw)

        let calc = #"hello \#(33 + 44)"#
        print(calc)
    }

    public static void functionDemo() 
    {
        /*
        @ function
        ===
        * concept: black box
        * pattern: TNP
        * feature:
            - regular
            - [x]anonymous
            - lambda
            - [x]immediate
            
            - function pointer
            - [x]decorator
            - [x]generator
            - [x]function in function
            - class in function

            - return_type
                $ ByVal
                $ ByRef
                $ ByPtr
            
            - func_name
                $ overload
                $ operator overload
                $ function template

            - args
                $ ByVal
                $ ByRef
                $ ByPtr

            - keywords
                $ inline vs macro
                $ const
                $ constexpr
                $ noexcept
                $ [[deprecated]]
        ===
        */ 

        func fibonacci(arg n: Int) -> Int {
            return n < 2 ? 1 : fibonacci(n-1) + fibonacci(n-2)
        }

        func factorial(arg n: Int) -> Int {
            return n < 2 ? 1 : n * factorial(n-1)
        }

        print("fibonacci(5), \(fibonacci(5))")
        print("factorial(5), \(factorial(5))")

        func greet(name: String) -> () {
            print("hello \(name)")
        }
        greet("TS")

        func minMax(arr: [Int]) -> (min: Int, max: Int)? {
            if arr.isEmpty() { return nil }
            let sortedArr: [Int] = sorted(arr, {$0 < $1})
            // or
            // sorted(arr, <)
            // arr.sort(){$0 < $1}
            return (sortedArr.first, sortedArr.last)
        }

        if let rv = minMax(array: [8, -6, 2, 109, 3, 71]) {
            print("min : \(rv.min), max : \(rv.max)")
        }

        // cmp: implicit return
        func greet1(for name: String) -> String {
            return "hello \(name)"
        }
        print(greet1(for: "TS"))

        func greet2(for name: String) -> String {
            "hello \(name)"
        }
        print(greet2(for: "TS"))

        func greet3(_ name: String) -> String {
            "hello \(name)"
        }
        print(greet3("TS"))

        func greet4(_ name: String = "TS") -> String {
            "hello \(name)"
        }
        print(greet4())
        
        // params or variadic args, same as spread operator in JS
        func arithmeticResult(_ numbers: Double...) -> Double {
            var total: Double = 0
            numbers.forEach{ num in
                total += num
            }
            return total / Double(numbers.count)
        }
        print("arithmeticResult(1, 2, 3, 4, 5) : \(arithmeticResult(1, 2, 3, 4, 5))")
        
        // ByRef
        func swapInts(_ a: Int, _ b: Int) -> () {
            let tmp  = a
            a = b
            b = tmp
        }

        var a, b: Int
        a = 69; b = 42
        print("after swap, a : \(a), b : \(b)")
        swapInts(&a, &b)
        print("after swap, a : \(a), b : \(b)")

        // function as argument
        func printMathResult(_ mathFunc: (Int, Int)->Int, _ a: Int, _ b: Int) -> () {
            print("math result: \(mathFunc(a, b))")
        }
        func myMathFunc(_ x: Int, _ y: Int) -> Int {
            x + y
        }
        printMathResult(mathFunc: myMathFunc, 3, 4)

        // function as return_type
        func stepForward(_ step: Int) -> Int {
            return step + 1
        }

        func stepBackward(_ step: Int) -> Int {
            return step - 1
        }
        
        func chooseStepFunction(_ backward: Bool) -> (Int) -> Int {
            return backward ? stepBackward : stepForward
        }

        let currentVal = 3
        let moveNearToZero = chooseStepFunction(backward: currentVal > 0)

        print("count to zero: ")
        while currentVal != 0 {
            print("\(currentVal)...")
            currentVal = moveNearToZero(currentVal)
        }
        print("zero!")

        // nested function
        func chooseStepFunction2(_ backward: Bool) -> (Int) -> Int {
            func stepForward(_ n: Int) -> Int { step + 1 }
            func stepBackward(_ n: Int) -> Int { step - 1 }
            return backward ? stepBackward : stepForward
        }

        /* 
        @ lambda or closure
        { (arglable parameter: T) -> U in
            // statement;
            return
        }
        */
        let names = ["Chris", "Alex", "Ewa", "Barry", "Daniella"]
        func back(_ s1: String, _ s2: String) -> Bool {
            return s1 > s2
        }
        var reverseName1 = names.sorted(by: back)

        // or
        var reverseName2 = names.sorted(by: {
            (_ s1: String, _ s2: String) -> Bool in
            return s1 > s2
        })

        var reverseName3 = names.sorted(by: { s1, s2 in return s1 > s2})

        var reverseName4 = names.sorted(by: {s1, s2 in s1 > s2})

        var reverseName5 = names.sorted(by: {$0 > $1})

        var reverseName6 = names.sorted(by: >)

        var reverseName7 = names.sorted({$0 > $1})
        // @ tail enclusure
        var reverseName8 = names.sorted() {$0 > $1}
        var reverseName9 = names.sorted {$0 > $1}

        let digitalNumbers = [
            1: "One",
            2: "Two",
            3: "Three",
            4: "Four",
            5: "Five",
            6: "Six",
            7: "Seven",
            8: "Eight",
            9: "Nine"
        ]

        let numbers: Array(Int) = [12, 159, 123]

        let strings = numbers.map {
            (number)->String in 
            var str = ""
            var number = number // why? function / closure argment is const in Swift
            repeat {
                str += digitalNumbers[number%10]!
                number /= 10
            } while number > 0
            return str
        }
        print()

        /* 
        @ escape closure; yeah, it is similar with `delegate, event` EventHandler concept in C#
        $ passing a closure -> a function
        $ the closure executed after function's return
        */

        var completionHandlers: [() -> Void] = []
        func someFunctionWithEscapingClosure(completionHandlers: @escaping () -> Void) {
            completionHandlers.append(completionHandlers)
        }

        func someFunctionWithNonEscapingClosure(closure: () -> Void) {
            closure()
        }

        class A {
            var x = 10
            func doSomething() {
                // ! when using `@escape` closure, u MUST use `self` explicitly
                someFunctionWithEscapingClosure { self.x = 100 }
                // u may use `self` implicitly with NonEscaping closure
                someFunctionWithNonEscapingClosure { x = 200 }
            }
        }

        let a: A = A()
        a.doSomething()
        print(a.x)

        completionHandlers.first?()
        print(a.x)

        // @ using autoclosure; it does not acception any args
        var wives: Array[String] = [
            "TS",
            "SCY",
            "WL",
            "LL",
            "XY"
        ]
        print(wives.count) // 5

        let wifeProvider: () -> String = { wives.remove(at: 9) }
        print(wives.count) // 5
        
        print("now have sex with \(wifeProvider())!")
        print(wives.count) // 4

        // @ explicit closure as args;
        func sexWith(wife wifeProvider: () -> String) {
            print("Now sexing with \(wifeProvider())!")
        }
        sexWith(wife: { wives.remove(at: 0) })

        // @ autoclosure as args
        func sexWith(wife wifeProvider: @autoclosure () -> String) {
            print("Now sexing with \(wifeProvider())!")
        }
        sexWith(wife: wives.remove(at: 0))

        // # using @autoclosure, @escaping at the same time
        var wifeProviders: [()->String] = []
        func collectWifeProviders(_ wifeProvider: @autoclosure @escaping ()->String) {
            wifeProviders.append(wifeProvider)
        }

        collectWifeProviders(wives.remove(at: 0))
        collectWifeProviders(wives.remove(at: 0))

        print("collected \(wifeProviders.count) closures")
        for wifeProvider in wifeProviders {
            print("Now sexing with \(wifeProvider())!")
        }

    }

    public static void statementDemo() 
    {
        /*
        @ statement
        ===
        * concept: link
        * pattern: symbol
        * feature:
            - arithmetic
                $ +, -, *, /, %
                $ (prefix)++, --; (postfix) ++, --

            - relational
                $ ==, !=
                $ >, >=
                $ <. <=

            - logic
                $ !
                $ &&
                $ ||

            - access
                $ (*ptr).
                $ ptr->

            - bitwise
                $ ~
                $ <<, >>
                $ &, |, ^

            - assign
                $ T var_name = val;
                $ T var_name(val);
                $ T var_name{val}
                $ T var_name = T(val);
                $ T var_name = T{val}

            - cast
                $ dynamic_cast
                $ static_cast
                $ const_cast
                $ reinterpret_cast
                $ C-style cast

            - op
                $ new
                $ delete

            - op
                $ .
                $ ,
                $ ;
                $ ()
                $ []
                $ {}
                $ <>

        ===
        */

        let x = Int(69), y: Int = 42;
        // a
        print("x = \(x), y = \(y); x + y : \(x + y)")
        print("x = \(x), y = \(y); x - y : \(x - y)")
        print("x = \(x), y = \(y); x * y : \(x * y)")
        print("x = \(x), y = \(y); x / y : \(x / y)")
        print("x = \(x), y = \(y); x % y : \(x % y)")

        // r
        print("x = \(x), y = \(y); x == y : \(x == y)")
        print("x = \(x), y = \(y); x != y : \(x != y)")
        print("x = \(x), y = \(y); x < y : \(x < y)")
        print("x = \(x), y = \(y); x <= y : \(x <= y)")
        print("x = \(x), y = \(y); x > y : \(x > y)")
        print("x = \(x), y = \(y); x >= y : \(x >= y)")

        // l
        print("x = \(x), y = \(y); !(x == x) : \(!(x == x))")
        print("x = \(x), y = \(y); (x == x) && (y ==y) : \((x == x) && (y ==y))")
        print("x = \(x), y = \(y); (x == x) || (y ==y) : \((x == x) || (y ==y))")

        // a
        struct A {
            var m_x:Int? = 1
            var m_y:Int? = 1
        }

        var a: A = A()
        print("a: \(a.m_X!), \(a.m_y!)")

        // b
        print("x = \(x), y = \(y); ~x : \(~x)")
        var x1: Int = x << 2
        print("x = \(x), y = \(y); x << 2 : \(x1)")
        x1 = x >> 2
        print("x = \(x), y = \(y); x >> 2 : \(x1)")
        print("x = \(x), y = \(y); x & y : \(x & y)")
        print("x = \(x), y = \(y); x | y : \(x | y)")
        print("x = \(x), y = \(y); x ^ y : \(x ^ y)")

        // assign
        var y1: Double = Double(2.71828)
        y1 = 3.14
        print("y1 : \(y1)")

        // [x]cast
        // [x]pp for storage
        // op for other
        var msg: String?
        msg = x % 2 == 0 ? "even" : "odd"
        print(msg)
    }

    public static void controlflowDemo() 
    {
        /*
        @ controlflow
        ===
        * concept: branch
        * pattern: branch
        * feature:
            - if...else if...else
            - switch...case...default
            - try...catch...
            - guard...else
        ===
        
        */ 

        func isLeapYear(year y: Int) -> Bool {
            return (y%4 == 0 && y%100 !=0) || (y%400 == 0);
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
                if d > 31 { return false }
            default:
                break
            }

            return true
        }

        print("setDate(2021, 5, 25)? : \(setDate(2021, 5, 25))")

        // @ using if to check API is available
        if #available(iOS 10, macOS 10.12, *) {
            // ... 
        } else {
            // ...
        }

        // @ pattern match
        let p1 = (9, 0)
        switch p1 {
        case (let distance, 0), (0, let distance):
            print("on an axis, \(distance) from the origin")
        default:
            print("Not on an axis")
        }

        func divisionZero(_ x: Int, _ y: Int) throws-> Double {
            return x / y
        }

        do {
            try divisionZero(10, 0)
        } catch {
            print("error out; in catch clause")
        }

        // @ guard, protect the rest of code once condition fails
        // ! `else` clause MUST have control statement(return/continue/break) to escape
        func greet(_ person: [String: String]) {
            guard let name = person["name"] else {
                return
            }
            print("hello \(name)!")

            guard let location = person["location"] else {
                print("I hope the weather i nice near you")
                return
            }

            print("I hope the weather is nice in \(location)")
        }

        greet(person: ["name" : "TS"])
        greet(person: ["name" : "ZL", "location" : "Shanghai"])
    }

    public static void LoopDemo() 
    {
        /*
        @ loop
        ===
        * concept: circle
        * pattern: circle
        * feature:
            - for(;;)
            - for(:)
            - while
            - do...while
        ===
        */ 
        
        // range
        var numbers: Range = 1...5
        numbers = ..<5
        print("numbers.contains(-1) : \(numbers.contains(-1))")
        print("numbers.contains(5)  : \(numbers.contains(5))")
        print("numbers.contains(4)  : \(numbers.contains(4))")

        // stride
        for countdown in stride(from: 10, to: 0, stride: -2) {
            print("\(countdown)...", separator: " ")
        }
        print()

        // iterator?
        
        // for...in
        for i in 1...5 {
            print("i = \(i)", separator: " ")
        }
        print()

        // forEach
        numbers.forEach{ num in
            print(num)
        }

        // while
        let arr = [Int]()
        for i in 1...10 where i % 2 == 1 {
            arr.append(i, separator: ", ")
        }
        print()
        
        // repeat..while
        var i: Int = arr.count -1
        repeat {
            print("\(i), \(arr[i])")
            i -= 1
        } while i >= 0
    }

    public static void classDemo() 
    {
        /*
        @ class
        ===
        * concept: sim
        * pattern: sim
        * feature:
            - Abstract
            - Encapsulation
            - Inheritance
                $ is-a
                $ has-a
                $ multiple inheritance
                $ MRO

            - Polymorphism

        * structure:
            ^ default ctor
            ^ default dtor
            ^ copy ctor
            ^ copy assignment operator
            ^ move ctor
            ^ move assignment operator

        * principles:
            # SRP
            # OCP
            # LSP
            # ISP
            # DIP
            # Delimiter principle

        * keywords:
            $ default
            $ explicit (operator opol for type conversion)
            $ override
            $ virtual
            $ =0 (abstract vs concret; abstract class is not allowed to create obj in C++)
        
        * privilage:
            % private
            % public
            % friend

        * other:
            & class vs struct vs enum
            & class template
            & dependency injection
            & class in class? 
        ===
        */ 

        // @ class
        class Warrior {
            var name: String
            var healthpoint: Int
            var attack: Int
            var defenece: Int
            var block: Bool

            init(_ name: String, _ healthpoint: Int,
                _ attacK: Int, _ defenece: Int,
                _ block: Bool) {
                self.name = name
                self.healthpoint = healthpoint
                self.attack = attack
                self.defence = defence
                self.block = block
            }

            func Attack(_ otherWarrior: Warrior) {

            }
        }

        class Battle {
            func startFight(_ warriorA: Warrior, _ warriorB: Warrior) {
                fightOn : while true {
                    switch Battle(warriorA, warriorB) {
                    case false:
                        print("Game Over")
                        break fightOn
                    case true:
                        print("Start fight again")
                        continue
                    default:
                        print("nothing")
                        break fightOn
                    }
                }
            }

            static func Battle() -> Bool {
                // TODO
                return true;
            }
        }

        protocol Teleport {
            func teleportResult()
        }

        class WarriorCanTeleport : Teleport {
            func teleportResult() -> Void {
                print("teleport success")
            }
        }

        class WarriorCantTeleport : Teleport {
            func teleportResult() -> Void {
                print("teleport failed")
            }
        }

        class MagicWarrior: Warrior {
            var teleportChance: Int = 0
            var teleportStatus: WarriorCanTeleport

            init(_ name: String, _ healthpoint: Int,
                _ attacK: Int, _ defenece: Int,
                _ block: Bool, _ teleportChange: Bool) {
                super.init(name, healthpoint, attack, defence, block)
                teleportChance = teleportChance
            }
        }

        // @ struct
        // ! in Swift, instances of struct/enum are passing `ByVal` just like C#, C++
        struct Resolution {
            var width:  Int = 0
            var height: Int = 0
        }

        class VideoMode {
            // ^ in real project, using dependency injection instead
            var resolution: Resolution = Resolution()
            var iterlaced = false
            var frameRate = 0.0
            var name: String?

            init(_ resolution: Resolution, _ interlaced: Bool = false,
                _ frameRate: Double = 0.0, _ name: String = "noname") {
                self.resolution = resolution
                self.interlaced = interlaced
                self.frameRate = frameRate
                self.name = name
            }
        }

        // @ property
        struct Point {
            var x: Int = 0
            var y: Int = 0
        }

        struct Size {
            var width: Int = 0
            var Height: Int = 0
        }

        struct Rect {
            var origin: Point()
            var size: Size()

            // @ getter and setter share the same concept in C#
            var center: Point {
                get {
                    let centerX = origin.x + (size.width / 2)
                    let centerY = origin.y + (size.height / 2)
                    return Point(x: centerX, y: centerY)
                }
                // @ just like C#
                set(newCenter) {
                    origin.x = newCenter.x - (size.width / 2)
                    origin.y = newCenter.y - (size.height / 2)
                }
            }
        
        }

        // @lazy initialization
        class DataImporter {
            var fileName = "data.txt"
        }

        class DataManager {
            // ^ keyword `lazy` has the same concept as `lazy<T>class` in C#
            // & https://docs.microsoft.com/en-us/dotnet/api/system.lazy-1?view=net-5.0
            lazy var importer = DataImporter()
            var data = [String]()
        }

        // @ propertyWrapper
        @propertyWrapper
        struct TwelveOrLess {
            private var number : Int
            
            init(number) {
                self.number = number
            }
            var wrappedValue: Int {
                get { return number }
                set { number = min(newValue, 12) }
            }
        }

        let manager = DataManager()
        manager.data.append("some data")
        manager.data.append("some more data")

        // @ using the struct TwelveOrLess to wrapper
        // @ ay, its concept is similar with @property in Python
        struct SmallRectangle {
            @TwelveOrLess var height: Int
            @TwelveOrLess var width: Int
        }

        class LevelTracker {
            static var highestUnlockedLevel = 1
            var currentLevel = 1

            static func unlock(_ level: Int) {
                if level > highestUnlockedLevel {
                    highestUnlockedLevel = level
                }
            }
            
            static func isUnlocked(_ level: Int) -> Bool {
                return level <= highestUnlockedLevel
            }

            @discardableResult
            mutating func advance(to level: Int) -> Bool {
                if LevelTracker.isUnlocked(level) {
                    currentLevel =  level
                    return true
                }
                return false
            }
        }
        // $ struct, enum are vale-type
        // $ it means regular methods cant mutate instance properties
        struct Point {
            var x: Double = 0.0
            var y: Double = 0.0
            mutating func moveBy(x deltaX: Double, y deltaY: Double) {
                // ^ mutating method assigns a new instance to self;
                self = Point(x: x + deltaX, y: x + deltaY)
            }
        }
        // $ enum
        enum TripleStateSwitch {
            case off, low, high
            mutating func next() {
                switch self {
                case .off:
                    self = .low
                case .low:
                    self = .high
                case .high:
                    self = .off
                }
            }
        }

        var ovenLight = TripleStateSwitch.low
        ovenLight.next() // high
        ovenLight.next() // off

    }

    public static void datastructureDemo() 
    {
        /*
        @ datastructure
        ===
        * concept: container
        * pattern: container
        * feature:
            - seq
            
                $ array -> fixed size
                $ vector
                $ list
                $ forward_list
                $ deque

            - adaptor
                $ stack
                $ queue
                $ priority_queue

            - associative
                $ map
                $ multimap
                $ set
                $ multiset

            - unordered associative
                $ unordered_set
                $ unordered_multiset
                $ unordered_map
                $ unordered_multimap
        ===
        */ 

        // tuple
        let (x, y) = (1, 2)
        print("x = \(x), y = \(y)")

        // array
        let arr0 = Array(repeat: 1, times: 5)
        for i in arr0 {
            print("\(i), \(arr0[i])")
        }

        let arr = [String]()
        arr.append("TS")
        arr.append("SCY")
        arr.append("XY")
        arr.append("LL")
        arr.append("XL")
        for name in arr[..<3] {
            print(name)
        }
        
        for (index, name) in arr.enumerate() {
            print("\(index) : \(name)")
        }

        // map
        var m = [Int: String]()
        m[1] = "TS"
        m[2] = "ZL"
        m[3] = "SCY"
        for (key, val) in m {
            print("\(key) : \(val)")
        }

        // set
        var s = Set<String>()
        s.add("TS")
        s.add("TS")
        s.add("TS")
        s.add("TS")

        for item in s {
            print(item)
        }

        // enum
        enum CompassPoint {
            case north
            case south
            case east
            case west
        }

        enum Wife {
            case "TS", "SCY", "XY"
        }

        var directionToTS = CompassPoint.west
        // @ after declared as CompassPoint, it is easy to change value
        directionToTS = .east
        // @ combine with `swith`
        switch directionToTS {
        case .north:
            print("Lots of planets have a north")
        case .south:
            print("Watch out for penguins")
        case .east:
            print("Where the sun rises")
        case .west:
            print("Where the skies are blue")
        }
        // @ to make `enum` iterable, inherit `CaseIterable` protocol
        enum Beverage: CaseIterable {
            case coffee, tea, juice
        }
        let numberOfChoices = Beverage.allCases.count
        print("\(numberOfChoices) beverages available")
        for beverage in Beverage.allCases {
            print(beverage)
        }

        enum Barcode {
            case upc(Int, Int, Int, Int)
            case qrCode(String)
        }

        var productBarcode = Barcode.upc(8, 85909, 51226, 3)
        productBarcode = .qrCode("ABCDEFGHIJKLMNOP")
        // @ extract details
        switch productBarcode {
        case .upc(let numberSystem, let manufacturer, let product, let check):
            print("UPC: \(numberSystem), \(manufacturer), \(product), \(check).")
        case .qrCode(let productCode):
            print("QR code: \(productCode).")
        }

        // @ recursive enum; the concept is good; but why take `enum` so far is bothering me
        // @ `enum` the concept itself just a simple type with E-R diagram(has-a relationship)
        enum arithmeticCalculation {
            case number: Int
            indirect case add: arithmeticCalculation = arithmeticCalculation.number + arithmeticCalculation.number
            indirect case multiply: arithmeticCalculation = arithmeticCalculation.number * arithmeticCalculation.number
        }

        // @

    }

    public static void algorithmDemo() 
    {
        /*
        @ algorithm
        ===
        * concept: calculation methods
        * pattern: world map of STL algorithm
        * feature:
            - permutation
            - queries
                ^ value queries
                    $ count
                    $ transform_inclusive_scan
                    $ transform_exclusive_scan
                    $ inclusive_scan
                    $ exclusive_scan

                ^ property queries
                ^ search
                ^ 2-ranges properties

            - secrete runes
                $ *_n
                $ *_if
                $ *_copy
                $ stable_*
                $ is_*
                $ is_*_until

            - movers
            - lone island
            - raw memory 
            - value modifier
            - structure changer
        ===
        */

        // ^ just like C#, Python, Swift packs algorithm into containers
        // ^ no need to do it like C++ STL
    }
}
