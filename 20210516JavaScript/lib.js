/*
JavaScript meta-lang review

@ZL, 20210516;

*/ 

const cls = require('./cls.js');

function print(x){
    console.log(x);
}

function variableDemo(){
    /*
    [ varialbe ]
    ===
    * concept: box
    * pattern: T N V
    * feature:
        * [x]variable template
        * primitive types(or meta type): 
            -- CSIL,
            -- FD, 
            -- BBD
            -- symbol

        * type traits
            -- IsXXX
            -- typeof

        * type conversion
            -- implicit, explicit
            -- downcast, upcasting
            -- Number()
            -- Boolean()
            -- String()

        * initialization
            -- resource acquisition is list initialization

        * keywords
            -- var
            -- let
            -- const

    ===
    
    */ 
    var x; x = 'a';
    let y = 69;
    const pi = 3.14;
    var z = true;

    print(`x = ${x}, type: ${typeof x}`);
    print(`y = ${y}, type: ${typeof y}`);
    print(`z = ${z}, type: ${typeof z}`);
    print(`pi = ${pi}, type: ${typeof pi}`);

    print(`Number->String: ${String(y)}`);
    print(`Boolean->String: ${String(z)}`);
    y = '42';
    print(`String->Number: ${Number(y)}`);

    x = Number(3.14);
    print(`x = Number(3.14); x = ${Number(x)}`);
    print(`x = ${x}, isFinite(x): ${isFinite(x)}`);
    print(`x = ${x}, isNaN(x): ${isNaN(x)}`);
    print(`x = ${x}, typeof: ${typeof x}, instanceof(x): ${x instanceof Number}`);
    z = Boolean(x);
    print(`z = ${z}, typeof: ${typeof z}, instanceof(z): ${z instanceof Boolean}`);
    
}

function functionDemo(){

    /*
    [ function ]
    ===
    * concept: black box
    * pattern: T N P
    * feature:
        * [x]function template
        * [x]decorator
        
        * regular
        * anonymous
        * generator
        * lambda
        * immediate
        
        * class inside function
        * function inside function
        
        * return_type: 
            - ByVal,
            - [x]ByRef,
            - [x]ByPointer

        * func_name: [x]overload
        * args
            - params, 
            - ByVal, 
            - [x]ByRef, obj only;
            - [x]ByPointer
    ===
    
    */ 

    function fibonacci(n){
        return n < 2? 1: fibonacci(n-1) + fibonacci(n-2);
    };

    function factorial(n){
        return n < 2? 1: n * factorial(n-1);
    };

    console.log("fibonacci(5) = ", fibonacci(5));
    console.log("factorial(5) = ",factorial(5));

    const f = function(x){
        return x * x;
    };

    console.log("anonymous function: f(5) = ", f(5)); // 25

    function* gen(n){
        yield n;
        yield n + 1;
        yield n + 2;
    };

    function* compute(n){
        for(let i=0; i < n; ++i){
            yield i;
        }
    };

    const g = gen(10);
    console.log(g.next());

    var n = 10;
    const h = compute(n);
    for(let i=0; i<n; i++){
        console.log(h.next());
    }

    const f1 = (name)=>{
        return `hello ${name}!`;
    };
    console.log(`lambda: f1('ZL') -> ${f1('TS')}`);

    (function(...data){
        var sum = 0;
        for(let item of data){
            sum += item;
        }
        console.log("immediate function: (1, 2, 3) ->", sum);
    })(1, 2, 3);

    function funcInFunc(n){
        function inner(n){
            return n + n;
        };
        return inner(n);
    };
    console.log("function inside function: funcInFunc(5) ->", funcInFunc(5));

    function clsInFunc(){
        class Person{
            _name;
            _age;
            constructor(name, age){
                this._name = name;
                this._age  = age;
            };

            ToString(){
                return `name: ${this._name}, age: ${this._age}`;
            };
        }
        return new Person('TS', 30);
    };

    console.log("class inside function: clsInFunc() ->", clsInFunc().ToString());

    var a = 42;
    function funcByVal(n){
        ++n;
    };
    console.log(`before,a = ${a}`);
    funcByVal(a);
    console.log(`after, a = ${a}`);

    a = [1, 2, 3];
    function funcByRef(obj){
        obj.unshift(4);
    }
    console.log(`before,a = ${a}`);
    funcByRef(a);
    console.log(`after, a = ${a}`);
}

function statementDemo(){
    /*
    [ statement ]
    ===
    * concept: linkage
    * pattern: symbol
    * feature:
        * arithmetic
            - +, -, *, /, %
            - ++(prefix), ++(postfix), --(prefix), --(postfix)
            - inplace
            
        * relational
            - ==, !=
            - >, >=
            - <. <=

        * logic
            - !
            - &&
            - ||
            
        * access
            - ->
            - (*ptr).

        * bitwise
            - <<, >>
            - ~
            - &
            - |
            - ^

        * assign
            - =
            - ()
            - {}

        * cast
            - dynamic_cast
            - static_cast
            - const_cast
            - reinterpreter_cast

        * op for storage
            - new
            - delete; it differs from delete in C/C++; rather smiilar with del in Python;

        * op for other
            - .
            - ()
            - ? :
            - ,
            - ;
            - {}
            - []
            - <>
            - ...
            
    ===
    
    */ 

    var x = 69, y = 42;

    // arithmetic
    console.log(`x = ${x}, y = ${y}; x + y = ${x + y}`);
    console.log(`x = ${x}, y = ${y}; x - y = ${x - y}`);
    console.log(`x = ${x}, y = ${y}; x * y = ${x * y}`);
    console.log(`x = ${x}, y = ${y}; x / y = ${x / y}`);
    console.log(`x = ${x}, y = ${y}; x % y = ${x % y}`);
    
    // relational
    console.log(`x = ${x}, y = ${y}; x == y : ${x == y}`);
    console.log(`x = ${x}, y = ${y}; x != y : ${x != y}`);
    console.log(`x = ${x}, y = ${y}; x > y  : ${x > y }`);
    console.log(`x = ${x}, y = ${y}; x >= y : ${x >= y}`);
    console.log(`x = ${x}, y = ${y}; x < y  : ${x < y }`);
    console.log(`x = ${x}, y = ${y}; x <= y : ${x <= y}`);
    
    // logic
    console.log(`x = ${x}; !x : ${!x}`);
    console.log(`x = ${x}, y = ${y}; x && y : ${x && y}`);
    console.log(`x = ${x}, y = ${y}; x || y : ${x || y}`);
    
    // access
    var p1 = new cls.Point(1, 1);
    console.log(p1.X);
    
    // bitwise
    x = 69; y = 42;
    x = x << 2;
    console.log(`x = ${x}; x << 2: ${x}`);
    x = 69; x = x >> 2;
    console.log(`x = ${x}; x >> 2: ${x}`);
    x = 69;
    console.log(`x = ${x}; ~x: ${~x}`);
    x = 69; y = 42;
    console.log(`x = ${x}, y = ${y}; x & y : ${x & y}`);
    console.log(`x = ${x}, y = ${y}; x | y : ${x | y}`);
    console.log(`x = ${x}, y = ${y}; x ^ y : ${x ^ y}`);

    // assign
    x = Boolean(x);
    console.log(`x = ${x}, type: ${typeof x}`);

    // [x]cast

    // op
    var p2 = new cls.Point(1, 2);
    console.log(p2.ToString());

    var obj = {
        'name' : 'TS',
        'sex'  : 'female',
        'age'  : 30,
    };

    console.log(obj);
    delete obj.sex;
    console.log(obj);

    // op, [skip]
}

function controlflowDemo(){
    /*
    [ controlflow ]
    ===
    * concept: branch
    * pattern: branch
    * feature:
        * if...else if...else;
        * switch...case..default;
        * try...catch...except;
        
    ===
    */ 
    function isLeapYear(year){
        return (year%4 == 0 && year%100 != 0)||(year%400 == 0);
    }

    function validDate(y, m, d){
        if(y < 0) { return false; }
        if(m < 0 || m > 12) { return false; }
        if(d < 0 || d > 31) { return false; }

        switch (m) {
            case 2: if(isLeapYear(y)){
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
    console.log('2010/2/30 reasonable? ->', validDate(2010, 2, 30));

    var name = "SugarSaisai";
    try {
        console.log(name[100]);
    }
    catch(ex) {
        // throw "String is immutable in JavaScript!";
        console.error(ex);
    }
    finally {
        console.log(name);
    }
}

function loopDemo(){
    /*
    [ loop ]
    ===
    * concept: circle
    * pattern: circle
    * feature:
        - for(;;)
        - foreach
        - for( in )
        - for( of )
        - while
        - do...while
    ===
    */ 
    var numbers = [1, 2, 3, 4, 5];
    for(let i=0; i<numbers.length; ++i){
        console.log(numbers[i]);
    }
    console.log("---\n")
    
    for(let elem of numbers){
        console.log(elem);
    }
    console.log("---\n")
    
    for(let elem in numbers){
        console.log(elem);
    }
    console.log("---\n")
    
    numbers.forEach((elem)=>{
        console.log(elem);
    });
    console.log("---\n")
    
    var i = 0;
    while (i < numbers.length){
        console.log(numbers[i]);
        i++;
    }
    console.log("---\n")
    
    do {
        console.log(numbers[i-1]);
        --i;
    } while (i > 0);
    console.log("---\n")
}

function classDemo(){
    
    /*
    [ class ]
    ===
    * concept: simulator
    * pattern: simulator
    * feature:
        * Abstract
        * Encapsulation
        * Inheritance
        * Polymorphism
        
        * SRP
        * OCP
        * LSP
        * ISP
        * DIP
        * Delimiter Principle;
    ===
    
    */ 
    p1 = new cls.Point(1, 1);
    p2 = new cls.Point(1, 2);
    
    console.log(p1.ToString())
    console.log(p2.ToString())

    var a1 = new cls.A();
    var b1 = new cls.B();

    console.log(a1.ToString());
    console.log(b1.ToString(), b1.BigDick());
    console.log("b1 is instanceof A? ->", b1 instanceof cls.A);
}

function ioDemo(){
    // covered
    console.log("covered in previous sections");
}

function datastructureDemo(){
    /*
    [ datastructure ]
    ===
    * concept: container
    * pattern: collection
    * feature:
        * seq
            - array
            - list
            - forward_list
            - dequeue

        * adaptor
            - stack
            - queue
            - priority_queue

        * associative
            - set
            - multiset
            - map
            - multimap
        * tree
        * heap
        * map
    ===
    */

    console.log("\n--- array/list --n");
    var numbers = [1, 2, 3, 4, 5];
    for(let number of numbers){
        console.log(number);
    }
    
    console.log("\n--- dict ---");
    var dict = {
        0 : "ZL",
        1 : "TS",
        2 : "SCY",
    };
    for(let i=0; i<3; ++i){
        console.log(dict[i]);
    }
        
    console.log("\n--- hashmap ---");
    var m1 = new Map();
    m1.set(0, "ZL");
    m1.set(1, "TS");
    m1.set(2, "SCY");
    for(let i=m1.size-1; i >= 0; i--){
        console.log(m1.get(i));
    }
    
    console.log("\n--- set ---");
    var A = new Set();
    A.add("ZL");
    A.add("SCY");
    A.add("TS");
    A.forEach((elem)=>{
        console.log(elem);
    })
}

function algorithmDemo(){
    /*
    [ algorithm ]
    ===
    * concept: solution
    * pattern: na
    * feature:
        * sort
            - section sort
            - bubble sort
            - quick sort
            - heap sort

        * search
            - binary search
            - DFS
            - BFS
        
            * saleperson problem

        * divide and conquor
        
        * dynamic

        * evaluate algorithms
            * time complexity
                - O(1)
                - O(logn)
                - O(n)
                - O(nlogn)
                - O(n!)
            * space complexity
                - Big O
                - Big Θ
                - Big Ω
    ===
    
    */ 
    function intersection(A, B){
        // A ⋂ B
        var rv = new Set(A);
        for(let elem of A){
            if(!B.has(elem)){
                rv.delete(elem);
            }
        }
        return rv;
    };

    function symmeticDifference(A, B){
        // A ⊖ B
        var rv = new Set(A);
        for(let elem of B){
            if(A.has(elem)){
                rv.delete(elem);
            }
            else{
                rv.add(elem);
            }
        }
        return rv;
    };

    function difference(A, B){
        // A - B
        var rv = new Set(A);
        for(let elem of B){
            if(A.has(elem)){
                rv.delete(elem);
            }
        }
        return rv;
    };

    function union(A, B){
        // A ⋃ B
        var rv = new Set(A);
        for(let elem of B){
            if(!A.has(elem)){
                rv.add(elem);
            }
        }
        return rv;
    };

    var A = new Set([1, 2, 3, 4, 5]);
    var B = new Set([4, 5, 6, 7, 8]);
    console.log("A", A);
    console.log("B", B);
    console.log("intersection(A⋂B)         ->", intersection(A, B));
    console.log("symmetricDifference(A⊖B)  ->", symmeticDifference(A, B));
    console.log("difference(A-B)            ->", difference(A, B));
    console.log("union(A⋃B)                ->", union(A, B));
}

exports.variableDemo = variableDemo;
exports.functionDemo = functionDemo;
exports.statementDemo = statementDemo;
exports.controlflowDemo = controlflowDemo;
exports.loopDemo = loopDemo;
exports.classDemo = classDemo;
exports.ioDemo = ioDemo;
exports.datastructureDemo = datastructureDemo;
exports.algorithmDemo = algorithmDemo;
