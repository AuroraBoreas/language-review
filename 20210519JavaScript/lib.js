/*

JS meta review

@ZL, 20210519

*/ 
const cls = require('./cls.js');

function VariableDemo(){
    /*
    [ variable ]
    ===
    * concept: box
    * pattern: T N V
    * feature:
        * [x] variable template
        * primitive types
            - Char
            - [x]Short
            - Integer
            - Long
            - [x]Float
            - Double
            - [x]Byte
            - Boolean
            - [x]Decimal
            - symbol

        * Type traits
            - IsXXX
            - typeof
        
        * initialization
            - resource acquisition is initialization

        * Type conversion
            - downcasting, upcasting
            - implicit, explicit

        * V
            - [x]lvalue
            - [x]rvalue
        
        * Ref
            - [x]lvalue reference
            - [x]rvalue reference
        
        * keywords
            - var
            - const
            - let

        * storage
            - [x]static
            - [x]auto
            - [x]register
            - [x]extern
            - [x]mutable

        * scope
            - Locals
            - Enclosure
            - Globals
            - Builtins
        
        * lifetime
            - stack
            - heap
    ===
    */ 

    var x1; x1 = 69;
    let x2 = true;
    const pi = 3.14;

    console.log(`x1 = ${x1}, type: ${typeof x1}`);
    console.log(`x2 = ${x2}, type: ${typeof x2}`);
    console.log(`pi = ${pi}, type: ${typeof pi}`);

    var y1 = Number(42);
    let y2 = Boolean(1);
    const y3 = String("TS");
    console.log(`y1 = ${y1}, type: ${typeof y1}`);
    console.log(`y2 = ${y2}, type: ${typeof y2}`);
    console.log(`y3 = ${y3}, type: ${typeof y3}`);
    
    y1 = String(x1);
    y2 = Number(x2);
    let spi = String(pi);

    var z1 = parseInt(y1);
    var z2 = parseFloat(spi);
    
    console.log(`z1 = ${z1}, type: ${typeof z1}`);
    console.log(`z2 = ${z2}, type: ${typeof z2}`);
        
}

function FunctionDemo(){
    /*
    [ function ]
    ===
    * concept: black box
    * pattern: T N P
    * feature:
        * [x]function template
        * regular
        * anonymous
        * immediate
        * lambda
        * function pointer
        * nested function
        * [x]decorator
        * generator
        * class in function
        * return_type
            - ByVal
            - ByRef
            - [x]ByPointer
        * function name
            - [x]overload
        
        * paramters
            - ByVal
            - ByRef
            - [x]ByPointer
            - Params

    ===
    
    */
    
    function fibonacci(n){
        return n < 2? 1: fibonacci(n-1) + fibonacci(n-2);
    }

    function factorial(n){
        return n < 2? 1: n * factorial(n-1);
    }

    console.log(`fibonacci(5) = ${fibonacci(5)}`);
    console.log(`factorial(5) = ${factorial(5)}`);
    
    function mysum(a, b, c, d){
        function sum(...arr){
            let sum = 0;
            for(let elem of arr){
                sum += elem;
            }
            return sum;
        }

        return sum(a, b, c, d);
    }

    console.log(`mysum(1, 2, 3, 4) = ${mysum(1, 2, 3, 4)}`);
    
    const f1 = function(a, b){
        return a * a + b * b;
    };

    console.log(`f1(3, 4) = ${f1(3, 4)}`);

    (function(name){
        console.log(`hello ${name}, from anonymous function`);
    })("TS");

    const f2 = (n)=>{
        return n * 2;
    };

    console.log(`f2(4) = ${f2(4)}`);
    
    function ClassInFunction(){
        class Person{
            constructor(name, sex){
                this._name = name;
                this._sex  = sex;
            }

            ToString(){
                return `Person(${this._name}, ${this._sex})`;
            }
        }

        return new Person('TS', 'Female');
    }

    console.log(`ClassInFunction: ${ClassInFunction().ToString()}`);
    
    var x = 69;
    
    function plusOne(n){
        n++;
    }

    console.log(`before plus one, x = ${x}`);
    plusOne(x);
    console.log(`after plus one, x = ${x}`);

    var numbers = [1, 2, 3];

    function addOne(n){
        n.push(1);
    }
    console.log(`before add one, numbers = ${numbers}`);
    addOne(numbers);
    console.log(`after add one, numbers = ${numbers}`);
    
}

function StatementDemo(){
    /*
    [ statement ]
    ===
    * concept: link
    * pattern: symbol
    * feature:
        * Arithmetic
            - +, -, *, /, %
            - ++(prefix), ++(postfix), --(prefix), --(postfix)

        * Relational
            - ==, !=
            - >, >=
            - <, <=

        * Logical
            - !
            - &&
            - ||

        * Access
            - [x]->
            - .

        * Bitwise
            - <<, >>
            (power(x, 2), x << 2)
            - ~
            - &
            - |
            - ^

        * Cast
            - dynamic_cast<T*>(U*);
            - static_cast<T*>(U*);
            - const_cast<T*>(U*);
            - reinterpreter_cast<T*>(U*); C-Style cast;

        * Operator for storage
            - new
            - delete

        * Operator for other
            - ? : ;
            - ()
            - []
            - {}
            - <>
            - ``
            - =>

    ===
    */ 

    var x = 69, y = 42;

    // a
    console.log(`x = ${x}, y = ${y}; x + y : ${x + y}`);
    console.log(`x = ${x}, y = ${y}; x - y : ${x - y}`);
    console.log(`x = ${x}, y = ${y}; x * y : ${x * y}`);
    console.log(`x = ${x}, y = ${y}; x / y : ${x / y}`);
    console.log(`x = ${x}, y = ${y}; x % y : ${x % y}`);
    
    // r
    console.log(`x = ${x}, y = ${y}; x == y : ${x == y}`);
    console.log(`x = ${x}, y = ${y}; x != y : ${x != y}`);
    console.log(`x = ${x}, y = ${y}; x > y  : ${x >  y}`);
    console.log(`x = ${x}, y = ${y}; x >= y : ${x >= y}`);
    console.log(`x = ${x}, y = ${y}; x < y  : ${x <  y}`);
    console.log(`x = ${x}, y = ${y}; x <= y : ${x <= y}`);
    
    // l
    console.log(`x = ${x}; !x : ${!x}`);
    console.log(`x = ${x}, y = ${y}; x && y : ${x && y}`);
    console.log(`x = ${x}, y = ${y}; x || y : ${x || y}`);
    
    // a
    var p1 = new cls.Point(1, 1);
    p1.ToString();
    
    // bitwise
    x = 69; y = 42;
    x = x << 2;
    console.log(`x = ${x}; x << 2 : ${x}`);
    x = 69;
    x = x >> 2;
    console.log(`x = ${x}; x >> 2 : ${x}`);
    x = 69;
    console.log(`x = ${x}; ~x     : ${~x}`);
    
    x = 69;
    console.log(`x = ${x}, y = ${y}; x & y : ${x & y}`);
    console.log(`x = ${x}, y = ${y}; x | y : ${x | y}`);
    console.log(`x = ${x}, y = ${y}; x ^ y : ${x ^ y}`);

    // a
    x = Number(y);
    console.log(`x = ${x}`);
    
    // op
    var p2 = new cls.Point(2, 3);
    
    var ZL = {
        'name' : 'ZL',
        'age'  : 35,
        'ToString' : function(){ return `name: ${this.name}, age: ${this.age}`; }
    };

    console.log(`before delete; ${ZL.ToString()}`);    
    delete ZL.ToString;
    console.log(`after delete; ${ZL.ToString()}`);   

    // op
    var s = x < 100? `x = ${x} < 100` : `x = ${x} >= 100`; 
    console.log(x);
    
}

function ControlFlowDemo(){

    /*
    [ controlflow ] 
    ===
    * concept: branch
    * pattern: branch
    * feature:
        * if...else if.. else
        * switch..case..default
        * try...catch...finally 
    ===
    */

    function IsLeapYear(year){
        return (year%4 == 0 && year%100 != 0)||(year%400 == 0);
    }

    function setDate(y, m, d){
        if(y < 0) { return false; }
        if(m < 0 || m > 12) { return false; }
        if(d < 0 || d > 31) { return false; }
        
        switch(m){
            case 2: if(IsLeapYear(y)) {
                        if(d > 29) { return false; }
                    }
                    else {
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

    var d1 = new Date();
    console.log(`d1 = ${d1.toString()}, valid date? ${setDate(d1.getFullYear(), d1.getMonth(), d1.getDay())}`);
    
}

function LoopDemo(){
    /*
    [ loop ]
    ===
    * concept: circle
    * pattern: circle
    * feature:
        * for(;;)
        * for(of)
        * for(in)
        * while
        * do...while
        
    ===
    */ 

    var numbers = [1, 2, 3];
    console.log("\n--- for(;;) ---");
    for(let i=0; i<numbers.length; ++i){
        console.log(i, numbers[i]);
        }
    
    console.log("\n--- for(of) ---");
    for(let elem of numbers){
        console.log(elem);
    }
    
    console.log("\n--- for(in) ---");
    for(let elem in numbers){
        console.log(elem);
    }
    
    console.log("\n--- while ---");
    var i = 0;
    while(i < numbers.length-1){
        console.log(i, numbers[i]);
        i++;        
    }
    
    console.log("\n--- do...while ---");
    var i = numbers.length - 1;
    do {
        console.log(i, numbers[i]);
        --i;
    } while( i != 0);

}

function ClassDemo(){
    /*
    [ class ]
    ===
    * concept: simulator
    * pattern: simulator
    * feature:
        * Abstraction
        * Encapsulation
        * Inheritance
        * Polymorphsim
    
    * principle
        * SRP
        * OCP
        * LSP
        * ISP
        * DIP
        * Delimiter(or the least known principle)
    ===
    */ 

    var p1 = new cls.Point(1, 2);
    var p2 = new cls.Point(2, 3);

    console.log(`p1: ${p1.ToString()}`);
    console.log(`p2: ${p2.ToString()}`);
    
    var p3 = p1.Add(p2);
    console.log(`p3: ${p3.ToString()}`);
}

function DataStructureDemo(){
    /*
    [ datastructure ]
    ===
    * concept: containers
    * pattern: containers
    * feature:
        * seq
            - array
            - list
            - [x]forward_list
            - [x]dequeue

        * adapter
            - [x]queue
            - [x]priority_queue
            - [x]stack
        
        * associative
            - map
            - [x]multimap
            - set
            - [x]multiset
    ===
    */ 

    // seq
    var numbers = [1, 2, 3];
    console.log(`numbers: ${numbers}`);

    // adap

    // associative
    var m1 = new Map();
    m1.set(1, 'ZL');
    m1.set(1, 'TS');
    console.log(`m1: ${m1}`);

    var s1 = new Set();
    s1.add(1);
    s1.add(1);
    s1.add(2);
    s1.add(3);
    console.log(`s1: ${s1}`);    
    
}

function AlgorithmDemo(){
    /*
    [ algorithm ]
    ===
    * concept: method
    * pattern: na
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
   
   function intersection(A, B){
       // A⋂B
       let tmp = new Set(A);
       for(let elem of A){
           if(!B.has(elem)){
               tmp.delete(elem);
            }
        }
        return tmp;
    }

    function union(A, B){
        // A⋃B
        let tmp = new Set(A);
        for(let elem of B){
            if(!A.has(elem)){
                tmp.add(elem);
            }
        }
        return tmp;
    }
    
    function difference(A, B){
        // A-B
        let tmp = new Set(A);
        for(let elem of B){
            if(B.has(elem)){
                tmp.delete(elem);
            }
        }
        return tmp;
    }

    function symmetricDifference(A, B){
        // A⊖B
        let tmp = new Set(A);
        for(let elem of B){
            if(A.has(elem)){
                tmp.delete(elem);
            } else {
                tmp.add(elem);
            }
        }
        return tmp;
    }

    var A = new Set([1, 2, 3, 4, 5]);
    var B = new Set([4, 5, 6, 7, 8]);

    console.log(`A⋂B: ${intersection(A, B)}`);
    console.log(`A⋃B: ${union(A, B)}`);
    console.log(`A-B: ${difference(A, B)}`);
    console.log(`A⊖B: ${symmetricDifference(A, B)}`);

}


exports.VariableDemo = VariableDemo;
exports.FunctionDemo = FunctionDemo;
exports.StatementDemo = StatementDemo;
exports.ControlFlowDemo = ControlFlowDemo;
exports.LoopDemo = LoopDemo;
exports.ClassDemo = ClassDemo;
exports.DataStructureDemo = DataStructureDemo;
exports.AlgorithmDemo = AlgorithmDemo;