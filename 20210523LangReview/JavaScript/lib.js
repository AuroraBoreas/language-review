/*
JavaScript, meta review

@ZL, 20210523

*/ 

const cls = require('./cls.js');

function variableDemo() {
    /*
    @ variable
    ===
    * concept: box
    * pattern: TNV
    * feature:
        - primitive types(meta types)
            $ [x]char
            $ [x]short
            $ int
            $ long

            $ float
            $ double
            $ [x]long double

            $ [x]byte
            $ boolean
            $ [x]decimal

            $ symbol
            $ string

        - type traits(reflect)
        - type conversion
            $ implicit vs explicit
            $ downcasting vs upcasting
            $ narrowing

        - initialization
            $ resource acquisition is initialization
            $ late-binding, early-binding
            $ [x]copy assignment operator
            $ [x]copy ctor
            $ [x]list initialization

        - ByVal, ByRef, ByPtr
            $ ByVal
                ~ [x]lvalue
                ~ [x]rvalue
            $ ByRef
                ~ [x]r-ref
                ~ [x]l-ref
            $ ByPtr
                ~ [x]raw pointer
                ~ array
                ~ [x]smart pointer

        - variable template
            $ generic

        - keywords
            $ storage
                ~ [x]static
                ~ const
                    % [x]const and variable
                    % [x]const and pointer
                    % [x]const and function
                ~ [x]extern
                ~ [x]register
                ~ [x]auto
                ~ var --> global in JS
                ~ let --> local in JS
            
            $ compile time
                ~ [x]constexpr
                ~ [x]string literal

        - parameter vs argument
            $ argument means actual variable
            $ parameter means placeholder variable
    ===    
    */ 

    // Number, String, Boolean
    var x1 = 69;
    let x2 = Number(42);
    const pi = 3.14;
    var b = Bolean(1);
    let s = "hello TS";

    console.log(`x1 = ${x1}, type: ${typeof x1}`);
    console.log(`x2 = ${x2}, type: ${typeof x2}`);
    console.log(`pi = ${pi}, type: ${typeof pi}`);
    console.log(`b = ${b}, type: ${typeof b}`);
    console.log(`s = ${s}, type: ${typeof s}`);

    // type conversion
    let sx1 = String(x1);
    let sx2 = String(x2);
    let bpi = Boolean(pi);
    let rv = parseInt(s);
    console.log(`sx1 = ${sx1}`);
    console.log(`sx2 = ${sx2}`);
    console.log(`bpi = ${bpi}`);
    console.log(`rv = ${rv}`);
}

function functionDemo() {
    /*
    @ function
    ===
    * concept: black box
    * pattern: TNP
    * feature:
        - regular
        - anonymous
        - lambda
        - immediate
        
        - function pointer
        - [x]decorator
        - generator
        - function in function
        - class in function

        - return_type
            $ ByVal
            $ ByRef
            $ [x]ByPtr
        
        - func_name
            $ [x]overload
            $ [x]operator overload
            $ [x]function template

        - args
            $ ByVal
            $ ByRef
            $ [x]ByPtr

        - keywords
            $ [x]inline vs macro
            $ [x]const
            $ [x]constexpr
            $ [x]noexcept
            $ [x][[deprecated]]
    ===
    */ 

    function fibonacci(n) {
        return n < 2? 1: fibonacci(n-1) + fibonacci(n-2);
    }

    function factorial(n) {
        return n < 2? 1: n * factorial(n-2);
    }

    const f1 = function(n) {
        return n * n;
    };

    const f2 = (a, b)=>{
        return f1(a) + f1(b);
    };

    (function(x, y){
        console.log(`immediate function1; x = ${x}, y = ${y}`);
    })(3, 4);
    
    ((x, y)=>{
        console.log(`immediate function1; x = ${x}, y = ${y}`);
    })(5, 6);
    
    console.log(`fibonacci(5) : ${fibonacci(5)}`);
    console.log(`factorial(5) : ${factorial(5)}`);
    console.log(`lamda(3, 4) : ${f2(3, 4)}`);

    function runManyTimes(n) {
        function hello(name) {
            console.log(`hello ${name}`);
        }

        for(let i=0; i<n; i++)
        {
            hello(i);
        }
    }

    runManyTimes(3);

    function* gen(n) {
        for(let i=0; i < n; ++i)
        {
            yield i;
        }
    }
    
    const g1 = gen(10);
    for(let i=0; i<10; ++i) {
        console.log(g1.next());
    }

    function clsInFunction(name, age) {
        class Person {
            _name; _age;
            constructor(name, age) {
                this._name = name;
                this._age = age;
            }
            ToString() {
                return `\nname: ${this._name}\nage: ${this._age}`;
            }
        }

        return new Person(name, age);
    }

    console.log(clsInFunction("TS", 30));

}

function statementDemo() {
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

        - [X]cast
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
            $ ::

    ===
    */

    var x = 69, y = 42;

    // arithmetic
    console.log(`x = ${x}, y = ${y}; x + y : ${x + y}`);
    console.log(`x = ${x}, y = ${y}; x - y : ${x - y}`);
    console.log(`x = ${x}, y = ${y}; x * y : ${x * y}`);
    console.log(`x = ${x}, y = ${y}; x / y : ${x / y}`);
    console.log(`x = ${x}, y = ${y}; x % y : ${x % y}`);
    
    // relational
    console.log(`x = ${x}, y = ${y}; x == y : ${x == y}`);
    console.log(`x = ${x}, y = ${y}; x != y : ${x != y}`);
    console.log(`x = ${x}, y = ${y}; x > y  : ${x > y}`);
    console.log(`x = ${x}, y = ${y}; x >= y : ${x >= y}`);
    console.log(`x = ${x}, y = ${y}; x < y  : ${x < y}`);
    console.log(`x = ${x}, y = ${y}; x <= y : ${x <= y}`);
    
    // logic
    console.log(`x = ${x}, y = ${y}; !x : ${!x}`);
    console.log(`x = ${x}, y = ${y}; x && y : ${x && y}`);
    console.log(`x = ${x}, y = ${y}; x || y : ${x || y}`);
    
    // access
    let p1 = new cls.A();
    console.log(`access : ${p1.ToString()}`);
    
    // bitwise
    console.log(`x = ${x}, y = ${y}; ~x : ${~x}`);
    let x1 = x << 2;
    console.log(`x = ${x}, y = ${y}; x << 2 : ${x1}`);
    x1 = x >> 2;
    console.log(`x = ${x}, y = ${y}; x >> 2 : ${x1}`);

    console.log(`x = ${x}, y = ${y}; x & y : ${x & y}`);
    console.log(`x = ${x}, y = ${y}; x | y : ${x | y}`);
    console.log(`x = ${x}, y = ${y}; x ^ y : ${x ^ y}`);

    // assign
    let y1; y1 = 69;
    console.log(`y1 = ${y1}, type: ${typeof y1}`);
    y1 = String(y1);
    console.log(`y1 = ${y1}, type: ${typeof y1}`);
    
}

function controlflowDemo() {
    /*
    @ controlflow
    ===
    * concept: branch
    * pattern: branch
    * feature:
        - if...else if...else
        - switch...case...default
        - try...catch...
    ===
    
    */ 

    function isLeapYear(year) {
        return (year%4 == 0 && year%100 != 0) || (year%400 ==0);
    }

    function setDate(year, month, day) {
        if(year < 0) { return false; }
        if(month < 0 || month > 12) { return false; }
        if(day < 0 || day > 31) { return false; }

        switch(month)
        {
            case 2: if(isLeapYear(year)) {
                        if(day > 29) { return false; }
                    } else {
                        if(day > 28) { return false; }
                    }
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(day > 31) { return false; }
        }

        return true;
    }

    console.log(`setDate(2021, 5, 24) : ${setDate(2021, 5, 24)}`);

}

function loopDemo() {
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

    console.log("\n--- for(;;) ---");
    var numbers = [1, 2, 3];
    for(let i=0; i<numbers.length; ++i) {
        console.log(`${i}, ${numbers[i]}`);
    }
    
    console.log("\n--- for(let...of...) ---");
    for(let elem of numbers) {
        console.log(elem);
    }
    
    console.log("\n--- for(let...in...) ---");
    for(let index in numbers) {
        console.log(`${index}, ${numbers[index]}`);
    }
    
    console.log("\n--- forEach ---");
    numbers.forEach((elem)=>{
        console.log(`forEach loop: ${elem}`);
    });
    
    let i = 0;
    console.log("\n--- while ---");
    while(i < numbers.length - 1) {
        console.log(`${i}, ${numbers[i]}`);
        ++i;
    }
    
    i = numbers.length - 1;
    console.log("\n--- do...while ---");
    do {
        console.log(`${i}, ${numbers[i]}`);
        i--;
    } while(i >= 0);

}

function classDemo() {
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

    const p1 = new cls.Person("TS", 30);
    const p2 = new cls.Teacher("ZL", 35, "Computer Science");

    console.log(`${p1.ToString()}, ${p2.ToString()}, p2 instanceof p1: ${p2 instanceof p1}`);

}

function datastructureDemo() {
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

    let numbers = [1, 2, 3, 4];
    console.log("\n--- array ---");
    numbers.forEach((elem)=>{
        console.log(elem);
    });
    
    console.log("\n--- map ---");
    let m = new Map();
    m.set(1, "ZL");
    m.set(2, "TS");
    m.set(3, "SCY");
    m.forEach((key, val)=>{
        console.log(`${key}, ${val}`);
    });

    console.log("\n--- set ---");
    let s = new Set();
    s.add("TS");
    s.add("ZL");
    s.add("TS");
    s.add("SCY");
    s.add("TS");
    s.forEach((elem)=>{
        console.log(`${elem}`);
    });
}

function algorithmDemo() {
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
    
    function intersection(A, B) {
        let tmp = new Set(A);
        for(let elem of A) {
            if(!B.has(elem)) {
                tmp.delete(elem);
            }
        }
        return tmp;
    }

    function union(A, B) {
        let tmp = new Set(A);
        for(let elem of B) {
            if(!A.has(elem)) {
                tmp.add(elem);
            }
        }
        return tmp;
    }

    function difference(A, B) {
        let tmp = new Set(A);
        for(let elem of B) {
            if(A.has(elem)) {
                tmp.delete(elem);
            }
        }
        return tmp;
    }

    function symmetricDifference(A, B) {
        let tmp = new Set(A);
        for(let elem of B) {
            if(A.has(elem)) {
                tmp.delete(elem);
            } else {
                tmp.add(elem);
            }
        }
        return tmp;
    }

    let A = new Set([1, 2, 3, 4]);
    let B = new Set([3, 4, 5, 6]);
    
    function print_set(comment, s) {
        let rv = ", ";
        s.forEach((elem)=>{
            rv += elem;
        });
        console.log(comment + rv);
    }

    print_set("A", A);
    print_set("B", B);

    print_set("A⋂B", intersection(A, B));
    print_set("A⋃B", union(A, B));
    print_set("A-B", difference(A, B));
    print_set("A⊖B", symmetricDifference(A, B));    

}