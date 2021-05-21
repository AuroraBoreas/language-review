/*

meta js review

@ZL, 20210521

*/ 

const cls = require("./cls.js");

function variableDemo() {
    /*
    [ variable ]
    ===
    * concept: box
    * pattern: T N V
    * feature:
        * primitive types
            - Char
            - Short
            - Integer
            - Long
            - Float
            - Double
            - Byte
            - Boolean
            - Decimal

        * initialization
            - resource acquisition is list initialization

        * type traits(reflection)
        * type conversion
            - downcast, upcast
            - implicit, explicit
        * Val
            - Lvalue
            - rvalue
        * Ref
            - lhs-ref
            - rhs-ref   
        * [x]Pointer
        * [x]variable template
        * keywords
            - var
            - let
            - const
    ===
    */ 

    var x1; x1 = 69;
    let x2 = 42.00;
    console.log(`x1 = ${x1}, type: ${typeof x1}, IsNaN: ${IsNaN(x1)}`);
    console.log(`x2 = ${x2}, type: ${typeof x2}, IsNaN: ${IsNaN(x2)}`);
    
    var y1 = String(x1);
    const y2 = Boolean(x2);
    console.log(`y1 = ${y1}, type: ${typeof y1}, IsNaN: ${IsNaN(y1)}`);
    console.log(`y2 = ${y2}, type: ${typeof y2}, IsNaN: ${IsNaN(y2)}`);
}

function functionDemo() {
    /*
    [ function ]
    ===
    * concept: black box
    * pattern: black box
    * feature:
        * paradigm
            - regular
            - anonymous
            - immediate
            - lambda
            - [x]function pointer
            - [x]decorator
            - generator
            - function inside function
            - class inside function

        * return_type
            - ByVal
            - ByRef
            - [x]ByPointer
        
            * func_name
            - [x]overload
            - [x]operator overload
        
            * args
            - ByVal
            - ByRef
            - [x]ByPointer
            - variadic
        
    ===
    
    */ 

    function fibonacci(n) {
        return n < 2? 1 : fibonacci(n-1) + fibonacci(n-2);
    }

    function factorial(n) {
        return n < 2? 1 : n * factorial(n-1);
    }
    console.log(`fibonacci(5): ${fibonacci(5)}`);
    console.log(`factorial(5): ${factorial(5)}`);

    const f1 = function(n) {
        return n * n;
    }
    console.log(`anonymous function: ${f1(2)}`); // 4

    (function(a, b) {
        console.log(`immediate function : ${a + b}`);
    })(3, 4); // 7

    const f2 = (a, b)=>{ return a * a + b * b; };
    console.log(`lambda : ${f2(3, 4)}`); // 25

    function* gen(n) {
        for(let i=0; i<n; ++i) {
            yield i;
        }
    }

    const g = gen(10);
    console.log(`generator: ${g.next()}`);
    console.log(`generator: ${g.next()}`);
    console.log(`generator: ${g.next()}`);
    console.log(`generator: ${g.next()}`);

    function funcInFunc(n) {
        function* gen(n) {
            for(let i=0; i<n; ++i) {
                yield i;
            }
        }
        
        const g = gen(10);
        let tmp = [];

        for(let i=0; i<10; ++i) {
            tmp.push(g.next());
        }
        return tmp;
    }
    console.log(`function inside function: ${funcInFunc(10)}`);

    function classInFunction(name, age) {
        class Person {
            constructor(name, age) {
                this.name = name;
                this.age  = age;    
            }
            ToString() {
                return `name: ${this.name}, age: ${this.age}`;
            }
        }
        return new Person(name, age);
    }
    console.log(`${classInFunction("TS", 30)}`);

    var x = 69;
    function addOne1(x) {
        x++;
    }
    console.log(`before addOne, x = ${x}`);
    addOne1(x);
    console.log(`after  addOne, x = ${x}`);
    
    var numbers = [1, 2];
    function addOne2(x) {
        numbers.push(x);
    }
    console.log(`before addOne, numbers = ${numbers}`);
    addOne2(numbers);
    console.log(`after  addOne, numbers = ${numbers}`);

    function sum(...args) {
        let rv = 0;
        for(let elem of args) {
            rv += elem;
        }
        return rv;
    }

    console.log(`variadic args: ${sum(1, 2, 3, 4)}`);
}

function statementDemo() {
    /*
    [ statement ]
    ===
    * concept: link
    * concept: symbol
    * feature:
        * arithmetic
            - +, -, *, /, %
            - ++(pre), --(pre), ++(post), --(post)

        * relational
            - ==, !=
            - >, >=
            - <, <=

        * logical
            - !
            - &&
            - ||

        * access
            - [x]->
            - .

        * bitwise
            - <<, >>
            - ~
            - &
            - |
            - ^

        * [x]cast
            - dynamic_cast
            - static_cast
            - const_cast
            - reinterpret_cast

        * op for storage
            - new
            - delete

        * op for other
            - ()
            - []
            - [x]<>
            - {}
            - .
            - =>

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
    // logical
    console.log(`x = ${x}; !x : ${!x}`);
    console.log(`x = ${x}, y = ${y}; x && y : ${x && y}`);
    console.log(`x = ${x}, y = ${y}; x || y : ${x || y}`);
    // access
    var p1 = new cls.Point(1, 1);
    console.log(`p1: ${p1.ToString()}`);
    // bitwise
    x = x << 2; // == x * x;
    console.log(`x = ${x}; x << 2 : ${x}`);
    x = 69; x = x >> 2;
    console.log(`x = ${x}; x >> 2 : ${x}`);
    x = 69;
    console.log(`x = ${x}, y = ${y}; x | y : ${x | y}`);
    console.log(`x = ${x}, y = ${y}; x & y : ${x & y}`);
    console.log(`x = ${x}, y = ${y}; x ^ y : ${x ^ y}`);
    // assign
    x = Number(3.14);
    // [x]cast

    // op for storage
    var obj = {
        'name' : 'TS',
        'age'  : 30
    };
    console.log(`obj : ${obj}`);
    delete obj.age;
    console.log(`obj : ${obj}`);

    // op for other: covered
    
}

function controlflowDemo() {
    /*
    [ controlflow ]
    ===
    * concept: branch
    * pattern: branch
    * feature:
        * if...else if...else
        * switch...case...default
        * try...catch...finally
    ===
    */ 

    function isLeapYear(year) {
        return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
    }

    function setDate(y, m, d) {
        if(y < 0) { return false; }
        if(m < 0 || m > 12) { return false; }
        if(d < 0 || d > 31) { return false; }
        switch(m) {
            case 2: if(isLeapYear(y)) {
                        if(d > 29) { return false; }
                    } else {
                        if(d > 28) { return false; }
                    }
                    break;
            case 4:
            case 6:
            case 9:
            case 11: if(d > 30) { return false; }
        }

        return true;
    }
    console.log(`setDate(2021, 5, 21), valid: ${setDate(2021, 5, 21)}`);

    function dividByZero(a, b) {
        try {
            rv = a / b;
            console.log(`rv = ${rv}`);
        }
        catch(ex) {
            console.error(ex);
        }
        finally {
            rv = "finally block!"
        }
        return rv;
    }

    dividByZero(10, 0);
}

function loopDemo() {
    /*
    [ loop ]
    ===
    * concept: circle
    * pattern: circle
    * feature:
        * for(;;)
        * for( of )
        * for( in )
        * forEach
        * while
        * do...while
    ===
    */ 

    var numbers = [ 1, 2, 3 ];

    console.log("\n--- for(;;) ---");
    for(let i=0; i<numbers.length; ++i) {
        console.log(`${i}, ${numbers[i]}`);
    }
    
    console.log("\n--- for( of ) ---");
    for(let elem of numbers) {
        console.log(`${elem}`);
    }
    
    console.log("\n--- for( in ) ---");
    for(let elem in numbers) {
        console.log(`${elem}`);
    }
    
    console.log("\n--- forEach ---");
    numbers.forEach((elem)=>{
        console.log(`${elem}`);
    })
    
    console.log("\n--- while ---");
    let i = 0;
    while(i < numbers.length - 1) {
        console.log(`${i}, ${numbers[i]}`);
        i++;
    }
    
    console.log("\n--- do...while ---");
    let i = numbers.length - 1;
    do {
        console.log(`${i}, ${numbers[i]}`);
        i--;
    } while(i > 0);

}

function classDemo() {
    /*
    [ class ]
    ===
    * concept: sim
    * pattern: sim
    * feature:
        * Abstraction
        * Encapsulation
        * Inheritance
        * Polymorphsm
        
    * design
        * SRP
        * OCP
        * LSP
        * ISP
        * DIP
        * Delimiter(or the least known principle)
    ===
    */ 

    var p1 = new cls.Point(1, 1);
    var p2 = new cls.Point(1, 2);
    console.log(`${p1.Add(p2).ToString()}`);
}

function datastructureDemo() {
    /*
    [ datastructure ]
    ===
    * concept: container
    * pattern: container
    * feature:
        * seq
            - array
            - list
            - forward_list
            - dequeue 

        * adapter
            - stack
            - queue
            - priority_queue
        
        * associative
            - map
            - multimap
            - set
            - multiset
    ===
    */ 

    var numbers = [1, 2, 3];
    console.log(`array: ${numbers}`);

    var m1 = new Map();
    m1.set(1, "ZL");
    m1.set(2, "TS");
    console.log(`Map: ${m1}, ${m1.size}`);

    var s1 = new Set();
    s1.add("ZL");
    s1.add("ZL");
    s1.add("TS");
    s1.add("TS");
    console.log(`Set: ${s1}, length: ${s1.size}`);
}

function algorithmDemo() {
    /*
    [ algorithm ]
    ===
    * concept: calculation method
    * pattern: iterator -> container
    * feature:
        * Iterator, const_iterator
        * Capacity
        * Access
        * Modification
        * List observation
        * Bucket
        * Hash policy
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

    var A = new Set([2, 3, 4, 5]);
    var B = new Set([4, 5, 6, 7]);

    function callback(elem) {
        console.log(elem);
    }

    console.log("A");
    A.forEach(callback);
    console.log("B");
    B.forEach(callback);

    console.log(`intersection(A, B)`);
    intersection(A, B).forEach(callback);
    console.log(`union(A, B)`);
    union(A, B).forEach(callback);
    console.log(`difference(A, B)`);
    difference(A, B).forEach(callback);
    console.log(`symmetricDifference(A, B)`);
    symmetricDifference(A, B).forEach(callback);

}

exports.variableDemo = variableDemo;
exports.functionDemo = functionDemo;
exports.statementDemo = statementDemo;
exports.controlflowDemo = controlflowDemo;
exports.loopDemo = loopDemo;
exports.classDemo = classDemo;
exports.datastructureDemo = datastructureDemo;
exports.algorithmDemo = algorithmDemo;